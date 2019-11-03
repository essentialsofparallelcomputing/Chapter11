cmake_minimum_required(VERSION 3.10)
project (StreamTriad)

set (CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3")

if (NOT CMAKE_OPENACC_VERBOSE)
    set(CMAKE_OPENACC_VERBOSE true)
endif (NOT CMAKE_OPENACC_VERBOSE)

if (CMAKE_C_COMPILER_ID MATCHES "PGI")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -alias=ansi")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

find_package(OpenACC)

if (CMAKE_C_COMPILER_ID MATCHES "PGI")
    set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -Minfo=accel")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
   set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -fopt-info-optimized-omp")
endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

if (CMAKE_OPENACC_VERBOSE)
    set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
endif (CMAKE_OPENACC_VERBOSE)

# Adds build target of stream_triad with source code files
add_executable(StreamTriad StreamTriad.c timer.c timer.h)

# Adds build target of stream_triad_par1 with source code files
add_executable(StreamTriad_par1 StreamTriad_par1.c timer.c timer.h)
set_source_files_properties(StreamTriad_par1.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par1 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_par2 with source code files
add_executable(StreamTriad_par2 StreamTriad_par2.c timer.c timer.h)
set_source_files_properties(StreamTriad_par2.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par2 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_par3 with source code files
add_executable(StreamTriad_par3 StreamTriad_par3.c timer.c timer.h)
set_source_files_properties(StreamTriad_par3.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par3 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_par4 with source code files
add_executable(StreamTriad_par4 StreamTriad_par4.c timer.c timer.h)
set_source_files_properties(StreamTriad_par4.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par4 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_kern1 with source code files
add_executable(StreamTriad_kern1 StreamTriad_kern1.c timer.c timer.h)
set_source_files_properties(StreamTriad_kern1.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_kern1 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_kern2 with source code files
add_executable(StreamTriad_kern2 StreamTriad_kern2.c timer.c timer.h)
set_source_files_properties(StreamTriad_kern2.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_kern2 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_kern2 with source code files
add_executable(StreamTriad_kern3 StreamTriad_kern3.c timer.c timer.h)
set_source_files_properties(StreamTriad_kern3.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_kern3 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake StreamTriad.dSYM ipo_out.optrpt)
