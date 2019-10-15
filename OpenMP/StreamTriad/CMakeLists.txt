cmake_minimum_required(VERSION 2.8)
project (StreamTriad)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3")

if (NOT CMAKE_OPENMP_VERBOSE)
    set(CMAKE_OPENMP_VERBOSE true)
endif (NOT CMAKE_OPENMP_VERBOSE)

message("CMAKE_C_COMPILER_ID ${CMAKE_C_COMPILER_ID}")
find_package(OpenMP)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMP_C_FLAGS "${OpenMP_C_FLAGS} -fstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMP_C_FLAGS "${OpenMP_C_FLAGS} -qalias=ansi")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")

#if (CMAKE_OPENMP_VERBOSE)
#    set(OpenMP_C_FLAGS "${OpenMP_C_FLAGS} ${OpenMP_C_VERBOSE}")
#endif (CMAKE_OPENMP_VERBOSE)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMP_C_FLAGS "${OpenMP_C_FLAGS} -foffload=nvptx-none")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMP_C_FLAGS "${OpenMP_C_FLAGS} -qoffload")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")


# This checks to see if the compiler supports the OpenMP4 standard and
# sets an OpenMP4_FOUND flag
if ("${OpenMP_C_SPEC_DATE}" LESS 201307)
  set (OpenMP4_FOUND false)
  message(STATUS "OpenMP4 not found: ${OpenMP_C_SPEC_DATE} needs to be greater than 201307")
else ()
  set (OpenMP4_FOUND true)
  message(STATUS "Found OpenMP4: " ${OpenMP_C_SPEC_DATE})
endif ()

# Adds build target of stream_triad with source code files
add_executable(StreamTriad StreamTriad.c timer.c timer.h)

# Adds build target of stream_triad_par1 with source code files
add_executable(StreamTriad_par1 StreamTriad_par1.c timer.c timer.h)
set_target_properties(StreamTriad_par1 PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(StreamTriad_par1 PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")

# Adds build target of stream_triad_par2 with source code files
add_executable(StreamTriad_par2 StreamTriad_par2.c timer.c timer.h)
set_target_properties(StreamTriad_par2 PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(StreamTriad_par2 PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")

# Adds build target of stream_triad_par3 with source code files
add_executable(StreamTriad_par3 StreamTriad_par3.c timer.c timer.h)
set_target_properties(StreamTriad_par3 PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(StreamTriad_par3 PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")


# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake StreamTriad.dSYM ipo_out.optrpt)
