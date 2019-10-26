cmake_minimum_required(VERSION 2.8)
#.rst:
# FindOpenMPAccel
# ----------
#
# Finds OpenMPAccel support
#
# This module can be used to detect OpenMPAccel support in a compiler.  If
# the compiler supports OpenMPAccel, the flags required to compile with
# OpenMPAccel support are returned in variables for the different languages.
# The variables may be empty if the compiler does not need a special
# flag to support OpenMPAccel.
#
# The following variables are set:
#
#    OpenMPAccel_C_FLAGS - flags to add to the C compiler for OpenMPAccel support
#    OpenMPAccel_C_VERBOSE - flags for more verbosity in compiler output
#    OPENMPACCEL_FOUND - true if openmp is detected
#

find_package(OpenMP)

# This checks to see if the compiler supports the OpenMP4 standard and
# sets an OpenMP4_FOUND flag
if ("${OpenMP_C_SPEC_DATE}" LESS 201307)
  set (OpenMP4_FOUND false)
  message(STATUS "OpenMP4 not found: ${OpenMP_C_SPEC_DATE} needs to be greater than 201307")
else ()
  set (OpenMP4_FOUND true)
  message(STATUS "Found OpenMP4: " ${OpenMP_C_SPEC_DATE})
  set(OPENMPACCEL_FOUND true)
endif ()

set (OpenMPAccel_C_FLAGS "${OpenMP_C_FLAGS}")

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -foffload=nvptx-none -foffload=-lm")
elseif (CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -fopenmp-targets=nvptx64-nvidia-cuda")
    # --cuda-path=$CUDA_HOME
elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS}")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -qsmp=noauto:omp -qoffload")
    #set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -qsmp -qoffload")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")


if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMPAccel_C_VERBOSE "${OpenMPAccel_C_VERBOSE} -fopt-info-all-omp")
elseif (CMAKE_C_COMPILER_ID MATCHES "PGI")
    #set(OpenMPAccel_C_VERBOSE "${OpenMPAccel_C_VERBOSE} -Minfo=all,ccff")
    set(OpenMPAccel_C_VERBOSE "${OpenMPAccel_C_VERBOSE} -Minfo=accel")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMPAccel_C_VERBOSE "${OpenMPAccel_C_VERBOSE} -Xptxas -v")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")

if (OPENMPACCEL_FOUND)
  message(STATUS "OpenMPAccel_C_FLAGS ${OpenMPAccel_C_FLAGS}")
  message(STATUS "OpenMPAccel_C_VERBOSE ${OpenMPAccel_C_VERBOSE}")
elseif (OPENMPACCEL_FOUND)
  message(STATUS "OPENMPACCEL_FOUND ${OPENMPACCEL_FOUND}")
endif (OPENMPACCEL_FOUND)
