cmake_minimum_required(VERSION 2.8)
project (Stencil)

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
add_executable(Stencil Stencil.c malloc2D.c malloc2D.h timer.c timer.h)

# Adds build target of stream_triad_par1 with source code files
add_executable(Stencil_par1 Stencil_par1.c malloc2D.c malloc2D.h timer.c timer.h)
set_target_properties(Stencil_par1 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(Stencil_par1 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par2 with source code files
add_executable(Stencil_par2 Stencil_par2.c malloc2D.c malloc2D.h timer.c timer.h)
set_target_properties(Stencil_par2 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(Stencil_par2 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par3 with source code files
add_executable(Stencil_par3 Stencil_par3.c malloc2D.c malloc2D.h timer.c timer.h)
set_target_properties(Stencil_par3 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(Stencil_par3 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Adds build target of stream_triad_par4 with source code files
add_executable(Stencil_par4 Stencil_par4.c malloc2D.c malloc2D.h timer.c timer.h)
set_target_properties(Stencil_par4 PROPERTIES COMPILE_FLAGS ${OpenMPAccel_C_FLAGS})
set_target_properties(Stencil_par4 PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake Stencil.dSYM ipo_out.optrpt)
