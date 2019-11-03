cmake_minimum_required(VERSION 3.10)
project (ShallowWater)

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
    #set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -Minfo=all,ccff")
    set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -Minfo=accel")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
   set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -fopt-info-optimized-omp")
endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

if (CMAKE_OPENACC_VERBOSE)
    set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
endif (CMAKE_OPENACC_VERBOSE)

# Adds build target of ShallowWater with source code files
add_executable(ShallowWater ShallowWater.c memory.c timer.c)

# Adds build target of ShallowWater_par1 with source code files
add_executable(ShallowWater_par1 ShallowWater_par1.c memory.c timer.c)
set_source_files_properties(ShallowWater_par1.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(ShallowWater_par1 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of ShallowWater_par2 with source code files
add_executable(ShallowWater_par2 ShallowWater_par2.c memory.c timer.c)
set_source_files_properties(ShallowWater_par2.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(ShallowWater_par2 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of ShallowWater_par3 with source code files
add_executable(ShallowWater_par3 ShallowWater_par3.c memory.c timer.c)
set_source_files_properties(ShallowWater_par3.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(ShallowWater_par3 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Adds build target of ShallowWater_par4 with source code files
add_executable(ShallowWater_par4 ShallowWater_par4.c memory.c timer.c)
set_source_files_properties(ShallowWater_par4.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
set_target_properties(ShallowWater_par4 PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake ShallowWater.dSYM ipo_out.optrpt)
