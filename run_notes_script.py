#!/usr/bin/env python

# CLI Args:
# JSON_TEST_FILE OUTPUT_FILE

# Ex:
# tests.json linux_laptop_tests.md

import os
import sys
import json
import tempfile
import subprocess

assert sys.version_info.major == 3

# String for formatting uname system information
uname_fmt = """sysname = {uname_info[0]}
release = {uname_info[2]}
version = {uname_info[3]}
machine = {uname_info[4]}\n\n"""


# Test error exceptions
class TestCallException(Exception):
    pass

class SourceConfigureException(TestCallException):
    pass

class SourceBuildException(TestCallException):
    pass

class SourceRunException(TestCallException):
    pass


# Dictionary for mapping platform to tester class
platform_testers = {}


class PlatformTest:
    def __init__(self, source_dir, run_script):
        self.source_dir = source_dir
        self.run_script = run_script

    def replace_dirs(self, str_out):
        """Function to replace the original source/script locations with
        descriptive strings"""
        return (str_out.replace(self.source_dir, "${SOURCE_DIR}")
                .replace(self.run_script, "${RUN_SCRIPT}"))

    @staticmethod
    def write_mach_info(fio):
        """Function to write machine information to stream"""
        uname_info = os.uname()
        fio.write(uname_fmt.format(uname_info=uname_info))

    def call_output(self, fio, call):
        """Helper function to do a subprocess call and write stdout/stderr to
        stream whether or not an error occurs"""
        try:
            output = subprocess.check_output(call, stderr=subprocess.STDOUT)
            fio.write(self.replace_dirs(output.decode("utf-8", "strict")))
        except subprocess.CalledProcessError as e:
            fio.write(self.replace_dirs(e.output.decode("utf-8", "strict")))
            raise

    def cmake_output(self, fio):
        """Function to do the cmake call, and write output to fio"""
        raise NotImplementedError()

    def build_output(self, fio):
        """Function to do the build (make) call, and write output to fio"""
        raise NotImplementedError()

    def run_output(self, fio):
        """Function to do the run call, and write output to fio"""
        raise NotImplementedError()


class LinuxTest(PlatformTest):
    def cmake_output(self, fio):
        try:
            self.call_output(fio, ["cmake", self.source_dir])
        except subprocess.CalledProcessError as e:
            raise SourceConfigureException("Configure Error") from e

    def build_output(self, fio):
        try:
            self.call_output(fio, ['make'])
        except subprocess.CalledProcessError as e:
            raise SourceBuildException("Build Error") from e

    def run_output(self, fio):
        try:
            self.call_output(fio, [self.run_script])
        except subprocess.CalledProcessError as e:
            raise SourceRunException("Run Error") from e


platform_testers["linux"] = LinuxTest


def output_section(fio, tester_call, name):
    """Convenience function to create headed section with label for a
    subprocess call"""
    error = False

    fio.write("### {}\n\n".format(name))
    fio.write("````\n")
    try:
        tester_call(fio)
        fio.write("````\n\n")
    except TestCallException:
        fio.write("````\n\n")
        fio.write("*FAILED*\n\n")
        raise


def generate_run_notes(output_file, tester, section_name):
    """Function to run full annotated test of a source directory"""
    output_file.write("## {} Run Notes\n\n".format(section_name))

    output_section(output_file, tester.cmake_output, "CMake Output")

    output_section(output_file, tester.build_output, "Build Output")

    output_section(output_file, tester.run_output, "Run Output")


def run_source_test(tester_class, source_dir, run_script, output_file):
    """Convenience function to run compilation test"""
    # Record init dir
    init_dir = os.getcwd()
    # Make all file refs absolute
    abs_source_dir = os.path.abspath(source_dir)
    if os.path.isfile(run_script):
        run_script = os.path.abspath(run_script)
    # Instatiate tester class
    tester = tester_class(abs_source_dir, run_script)
    # Create temp dir to run tests
    with tempfile.TemporaryDirectory() as tmpdirname:
        os.chdir(tmpdirname)
        try:
            generate_run_notes(output_file, tester, source_dir)
        finally:
            os.chdir(init_dir)


def run_file_tests(test_list, tester, output_file_name):
    with open(output_file_name, "w") as output_file:
        output_file.write("# Chapter Example Tests\n\n")
        output_file.write("## Machine Info\n\n")
        tester.write_mach_info(output_file)
        for test in test_list:
            print("Running test for {source_dir}:".format(**test))
            try:
                run_source_test(tester, test["source_dir"], test["run_script"], output_file)
            except TestCallException as e:
                print(e)
            else:
                print("Success!")


if __name__ == "__main__":
    # Get arguments
    assert len(sys.argv) == 3
    test_list_file = sys.argv[1]
    output_file = sys.argv[2]

    # Get correct tester class
    tester = None
    for key in platform_testers.keys():
        if sys.platform.startswith(key):
            tester = platform_testers[key]
    if tester is None:
        print("Unknown platform")
        sys.exit(1)
    
    # Load list of tests from json file
    with open(test_list_file, "r") as f:
        run_list = json.load(f)

    # Run tests
    run_file_tests(run_list, tester, output_file)
