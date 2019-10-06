cmake_minimum_required(VERSION 2.8)
project (StreamTriad)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3")

if (NOT CMAKE_OPENACC_VERBOSE)
    set(CMAKE_OPENACC_VERBOSE true)
endif (NOT CMAKE_OPENACC_VERBOSE)

if (NOT CUDA_ENABLED)
    set (CUDA_ENABLED ON CACHE BOOL "Use -DCUDA_ENABLED=OFF to disable CUDA")
endif (NOT CUDA_ENABLED)
if (NOT OPENACC_ENABLED)
    set (OPENACC_ENABLED ON CACHE BOOL "Use -DOPENACC_ENABLED=OFF to disable OpenACC")
endif (NOT OPENACC_ENABLED)

if (OPENACC_ENABLED)
    include(CheckCSourceCompiles)
    find_package(OpenACC)

    if (CMAKE_C_COMPILER_ID MATCHES "PGI")
        set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} -alias=ansi")
    elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
        set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} -fstrict-aliasing")
    endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

    if (CMAKE_OPENACC_VERBOSE)
        set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
    endif (CMAKE_OPENACC_VERBOSE)
endif (OPENACC_ENABLED)

# Adds build target of stream_triad with source code files
add_executable(StreamTriad StreamTriad.c timer.c timer.h)
target_compile_definitions(StreamTriad PRIVATE HAVE_OPENACC)
set_source_files_properties(StreamTriad.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_par1 with source code files
add_executable(StreamTriad_par1 StreamTriad_par1.c timer.c timer.h)
target_compile_definitions(StreamTriad_par1 PRIVATE HAVE_OPENACC)
set_target_properties(StreamTriad_par1 PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par1 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_par2 with source code files
add_executable(StreamTriad_par2 StreamTriad_par2.c timer.c timer.h)
target_compile_definitions(StreamTriad_par2 PRIVATE HAVE_OPENACC)
set_target_properties(StreamTriad_par2 PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_par2 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_kern1 with source code files
add_executable(StreamTriad_kern1 StreamTriad_kern1.c timer.c timer.h)
target_compile_definitions(StreamTriad_kern1 PRIVATE HAVE_OPENACC)
set_source_files_properties(StreamTriad_kern1.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_kern1 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of stream_triad_kern2 with source code files
add_executable(StreamTriad_kern2 StreamTriad_kern2.c timer.c timer.h)
target_compile_definitions(StreamTriad_kern2 PRIVATE HAVE_OPENACC)
set_source_files_properties(StreamTriad_kern2.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(StreamTriad_kern2 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake StreamTriad.dSYM ipo_out.optrpt)
