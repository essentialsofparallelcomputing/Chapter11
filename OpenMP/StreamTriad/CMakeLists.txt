cmake_minimum_required(VERSION 2.8)
project (StreamTriad)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3")

if (NOT CMAKE_OPENMPACCEL_VERBOSE)
    set(CMAKE_OPENMPACCEL_VERBOSE true)
endif (NOT CMAKE_OPENMPACCEL_VERBOSE)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -qalias=ansi")
elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -h restrict=a")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")

find_package(CUDA REQUIRED)
message("CUDA include ${CUDA_INCLUDE_DIRS}")
message("CUDA libs ${CUDA_LIBS_DIR}")
find_package(OpenMPAccel)

if (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -qreport")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -fopt-info-omp")
endif (CMAKE_C_COMPILER_ID MATCHES "XL")

if (CMAKE_OPENMPACCEL_VERBOSE)
    set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
endif (CMAKE_OPENMPACCEL_VERBOSE)

# Adds build target of stream_triad with source code files
add_executable(StreamTriad StreamTriad.c timer.c timer.h)

# Adds build target of stream_triad_par1 with source code files
add_executable(StreamTriad_par1 StreamTriad_par1.c timer.c timer.h)
set_target_properties(StreamTriad_par1 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(StreamTriad_par1 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par2 with source code files
add_executable(StreamTriad_par2 StreamTriad_par2.c timer.c timer.h)
set_target_properties(StreamTriad_par2 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(StreamTriad_par2 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par3 with source code files
add_executable(StreamTriad_par3 StreamTriad_par3.c timer.c timer.h)
set_target_properties(StreamTriad_par3 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(StreamTriad_par3 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par4 with source code files
add_executable(StreamTriad_par4 StreamTriad_par4.c timer.c timer.h)
set_target_properties(StreamTriad_par4 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(StreamTriad_par4 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par5 with source code files
add_executable(StreamTriad_par5 StreamTriad_par5.c timer.c timer.h)
set_target_properties(StreamTriad_par5 PROPERTIES COMPILE_FLAGS "${OpenMPAccel_C_FLAGS}")
target_include_directories(StreamTriad_par5 PRIVATE "${CUDA_INCLUDE_DIRS}")
set_target_properties(StreamTriad_par5 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS} ${CUDA_C_FLAGS}")
target_link_libraries(StreamTriad_par5 "${CUDA_LIBRARIES}")

# Adds build target of stream_triad_par6 with source code files
add_executable(StreamTriad_par6 StreamTriad_par6.c timer.c timer.h)
set_target_properties(StreamTriad_par6 PROPERTIES COMPILE_FLAGS "${OpenMPAccel_C_FLAGS}")
target_include_directories(StreamTriad_par6 PRIVATE "${CUDA_INCLUDE_DIRS}")
set_target_properties(StreamTriad_par6 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS} ${CUDA_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake StreamTriad.dSYM ipo_out.optrpt)
