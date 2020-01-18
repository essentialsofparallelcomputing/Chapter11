# Chapter Example Tests

## Machine Info

sysname = Linux
release = 4.15.0-72-generic
version = #81-Ubuntu SMP Tue Nov 26 12:20:02 UTC 2019
machine = x86_64

## ./OpenACC/StreamTriad/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_C: -fopenacc (found version "2.0") 
-- Found OpenACC_CXX: -fopenacc (found version "2.0") 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmppgni_6qq
````

### Build Output

````
Scanning dependencies of target StreamTriad_kern2
[  4%] Building C object CMakeFiles/StreamTriad_kern2.dir/StreamTriad_kern2.c.o
[  8%] Building C object CMakeFiles/StreamTriad_kern2.dir/timer.c.o
[ 12%] Linking C executable StreamTriad_kern2
[ 12%] Built target StreamTriad_kern2
Scanning dependencies of target StreamTriad_par1
[ 16%] Building C object CMakeFiles/StreamTriad_par1.dir/StreamTriad_par1.c.o
[ 20%] Building C object CMakeFiles/StreamTriad_par1.dir/timer.c.o
[ 25%] Linking C executable StreamTriad_par1
[ 25%] Built target StreamTriad_par1
Scanning dependencies of target StreamTriad_kern3
[ 29%] Building C object CMakeFiles/StreamTriad_kern3.dir/StreamTriad_kern3.c.o
[ 33%] Building C object CMakeFiles/StreamTriad_kern3.dir/timer.c.o
[ 37%] Linking C executable StreamTriad_kern3
[ 37%] Built target StreamTriad_kern3
Scanning dependencies of target StreamTriad_par3
[ 41%] Building C object CMakeFiles/StreamTriad_par3.dir/StreamTriad_par3.c.o
[ 45%] Building C object CMakeFiles/StreamTriad_par3.dir/timer.c.o
[ 50%] Linking C executable StreamTriad_par3
[ 50%] Built target StreamTriad_par3
Scanning dependencies of target StreamTriad_kern1
[ 54%] Building C object CMakeFiles/StreamTriad_kern1.dir/StreamTriad_kern1.c.o
[ 58%] Building C object CMakeFiles/StreamTriad_kern1.dir/timer.c.o
[ 62%] Linking C executable StreamTriad_kern1
[ 62%] Built target StreamTriad_kern1
Scanning dependencies of target StreamTriad
[ 66%] Building C object CMakeFiles/StreamTriad.dir/StreamTriad.c.o
[ 70%] Building C object CMakeFiles/StreamTriad.dir/timer.c.o
[ 75%] Linking C executable StreamTriad
[ 75%] Built target StreamTriad
Scanning dependencies of target StreamTriad_par4
[ 79%] Building C object CMakeFiles/StreamTriad_par4.dir/StreamTriad_par4.c.o
[ 83%] Building C object CMakeFiles/StreamTriad_par4.dir/timer.c.o
[ 87%] Linking C executable StreamTriad_par4
[ 87%] Built target StreamTriad_par4
Scanning dependencies of target StreamTriad_par2
[ 91%] Building C object CMakeFiles/StreamTriad_par2.dir/StreamTriad_par2.c.o
[ 95%] Building C object CMakeFiles/StreamTriad_par2.dir/timer.c.o
[100%] Linking C executable StreamTriad_par2
[100%] Built target StreamTriad_par2
````

### Run Output

````
Running StreamTriad
Average runtime for stream triad loop is 0.034202 secs

Running StreamTriad_kern1 -- kernel region, but compiler fails to parallelize loop
Average runtime for stream triad loop is 0.031463 secs

Running StreamTriad_kern2 -- kernel region, loop is parallelized
Average runtime for stream triad loop is 0.030774 secs

Running StreamTriad_kern3 -- data region eliminates data transfers
Average runtime for stream triad loop is 0.029600 secs

Running StreamTriad_par1 -- parallel loop region
Average runtime for stream triad loop is 0.030180 secs

Running StreamTriad_par2 -- added structured data region
Average runtime for stream triad loop is 0.029335 secs

Running StreamTriad_par3 -- added dynamic data region
Average runtime for stream triad loop is 0.029375 secs

Running StreamTriad_par4 -- allocating data only on device
Average runtime for stream triad loop is 0.030177 secs
````

## ./OpenACC/mass_sum/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_C: -fopenacc (found version "2.0") 
-- Found OpenACC_CXX: -fopenacc (found version "2.0") 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmp5jl206jp
````

### Build Output

````
Scanning dependencies of target mass_sum
[ 33%] Building C object CMakeFiles/mass_sum.dir/mass_sum.c.o
[ 66%] Building C object CMakeFiles/mass_sum.dir/main.c.o
[100%] Linking C executable mass_sum
[100%] Built target mass_sum
````

### Run Output

````
Mass Sum is 25000002.500000
````

## ./OpenACC/MaxRadius/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_C: -fopenacc (found version "2.0") 
-- Found OpenACC_CXX: -fopenacc (found version "2.0") 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmpztvz06hg
````

### Build Output

````
Scanning dependencies of target MaxRadius
[ 50%] Building C object CMakeFiles/MaxRadius.dir/MaxRadius.c.o
[100%] Linking C executable MaxRadius
CMakeFiles/MaxRadius.dir/MaxRadius.c.o: In function `main._omp_fn.0':
${SOURCE_DIR}/MaxRadius.c:21: undefined reference to `sqrt'
collect2: error: ld returned 1 exit status
CMakeFiles/MaxRadius.dir/build.make:94: recipe for target 'MaxRadius' failed
make[2]: *** [MaxRadius] Error 1
CMakeFiles/Makefile2:67: recipe for target 'CMakeFiles/MaxRadius.dir/all' failed
make[1]: *** [CMakeFiles/MaxRadius.dir/all] Error 2
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
````

*FAILED*

## ./OpenACC/Stencil/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_C: -fopenacc (found version "2.0") 
-- Found OpenACC_CXX: -fopenacc (found version "2.0") 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmp8smyxy8x
````

### Build Output

````
Scanning dependencies of target Stencil_par2
[  4%] Building C object CMakeFiles/Stencil_par2.dir/Stencil_par2.c.o
${SOURCE_DIR}/Stencil_par2.c: In function ‘main’:
${SOURCE_DIR}/Stencil_par2.c:21:24: error: array section is not contiguous in ‘map’ clause
 #pragma acc data create(x[0:jmax][0:imax], xnew[0:jmax][0:imax])
                        ^
${SOURCE_DIR}/Stencil_par2.c:21:24: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/Stencil_par2.c:23:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present(x[0:jmax][0:imax], xnew[0:jmax][0:imax])
                                  ^
${SOURCE_DIR}/Stencil_par2.c:23:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/Stencil_par2.c:31:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present(x[0:jmax][0:imax], xnew[0:jmax][0:imax])
                                  ^
${SOURCE_DIR}/Stencil_par2.c:31:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/Stencil_par2.c:42:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present(x[0:jmax][0:imax], xnew[0:jmax][0:imax])
                                  ^
${SOURCE_DIR}/Stencil_par2.c:42:34: error: array section is not contiguous in ‘map’ clause
CMakeFiles/Stencil_par2.dir/build.make:62: recipe for target 'CMakeFiles/Stencil_par2.dir/Stencil_par2.c.o' failed
make[2]: *** [CMakeFiles/Stencil_par2.dir/Stencil_par2.c.o] Error 1
CMakeFiles/Makefile2:99: recipe for target 'CMakeFiles/Stencil_par2.dir/all' failed
make[1]: *** [CMakeFiles/Stencil_par2.dir/all] Error 2
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
````

*FAILED*

## ./OpenACC/ShallowWater/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_C: -fopenacc (found version "2.0") 
-- Found OpenACC_CXX: -fopenacc (found version "2.0") 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmpm7nj34r4
````

### Build Output

````
Scanning dependencies of target ShallowWater_par1
[  5%] Building C object CMakeFiles/ShallowWater_par1.dir/ShallowWater_par1.c.o
[ 10%] Building C object CMakeFiles/ShallowWater_par1.dir/memory.c.o
[ 15%] Building C object CMakeFiles/ShallowWater_par1.dir/timer.c.o
[ 20%] Linking C executable ShallowWater_par1
[ 20%] Built target ShallowWater_par1
Scanning dependencies of target ShallowWater_par2
[ 25%] Building C object CMakeFiles/ShallowWater_par2.dir/ShallowWater_par2.c.o
${SOURCE_DIR}/ShallowWater_par2.c: In function ‘main’:
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
 #pragma acc enter data create( \
                              ^
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:30: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:55:9: error: ‘#pragma acc enter data’ has no data movement clause
 #pragma acc enter data create( \
         ^~~
${SOURCE_DIR}/ShallowWater_par2.c:63:36: error: array section is not contiguous in ‘map’ clause
   #pragma acc parallel loop present( \
                                    ^
${SOURCE_DIR}/ShallowWater_par2.c:63:36: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:63:36: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:77:36: error: array section is not contiguous in ‘map’ clause
   #pragma acc parallel loop present(H[:ny+2][:nx+2])
                                    ^
${SOURCE_DIR}/ShallowWater_par2.c:95:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present( \
                                  ^
${SOURCE_DIR}/ShallowWater_par2.c:95:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:95:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:105:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present( \
                                  ^
${SOURCE_DIR}/ShallowWater_par2.c:105:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:105:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present( \
                                  ^
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:122:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present( \
                                  ^
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:143:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop present( \
                                  ^
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:163:34: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:195:57: error: array section is not contiguous in ‘map’ clause
 #pragma acc parallel loop reduction(+:TotalMass) present(H[:ny+2][:nx+2])
                                                         ^
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
 #pragma acc exit data delete(H[:ny+2][:nx+2],    U[:ny+2][:nx+2],    V[:ny+2][:nx+2], \
                             ^
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:29: error: array section is not contiguous in ‘map’ clause
${SOURCE_DIR}/ShallowWater_par2.c:217:9: error: ‘#pragma acc exit data’ has no data movement clause
 #pragma acc exit data delete(H[:ny+2][:nx+2],    U[:ny+2][:nx+2],    V[:ny+2][:nx+2], \
         ^~~
CMakeFiles/ShallowWater_par2.dir/build.make:62: recipe for target 'CMakeFiles/ShallowWater_par2.dir/ShallowWater_par2.c.o' failed
make[2]: *** [CMakeFiles/ShallowWater_par2.dir/ShallowWater_par2.c.o] Error 1
CMakeFiles/Makefile2:104: recipe for target 'CMakeFiles/ShallowWater_par2.dir/all' failed
make[1]: *** [CMakeFiles/ShallowWater_par2.dir/all] Error 2
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
````

*FAILED*

## ./OpenMP/StreamTriad/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenMP_C: -fopenmp (found version "4.5") 
-- Found OpenMP_CXX: -fopenmp (found version "4.5") 
-- Found OpenMP: TRUE (found version "4.5")  
-- Found OpenMP4: 201511
-- OpenMPAccel_C_FLAGS -fopenmp -foffload=-lm
-- OpenMPAccel_C_VERBOSE  -fopt-info-all-omp
CUDA_TOOLKIT_ROOT_DIR not found or specified
-- Could NOT find CUDA (missing: CUDA_TOOLKIT_ROOT_DIR CUDA_NVCC_EXECUTABLE CUDA_INCLUDE_DIRS CUDA_CUDART_LIBRARY) 
-- Configuring done
-- Generating done
-- Build files have been written to: /tmp/tmp115_mrt2
````

### Build Output

````
Scanning dependencies of target StreamTriad_par8
[  4%] Building C object CMakeFiles/StreamTriad_par8.dir/StreamTriad_par6.c.o
[  8%] Building C object CMakeFiles/StreamTriad_par8.dir/timer.c.o
[ 12%] Linking C executable StreamTriad_par8
[ 12%] Built target StreamTriad_par8
Scanning dependencies of target StreamTriad_par7
[ 16%] Building C object CMakeFiles/StreamTriad_par7.dir/StreamTriad_par6.c.o
[ 20%] Building C object CMakeFiles/StreamTriad_par7.dir/timer.c.o
[ 25%] Linking C executable StreamTriad_par7
[ 25%] Built target StreamTriad_par7
Scanning dependencies of target StreamTriad_par1
[ 29%] Building C object CMakeFiles/StreamTriad_par1.dir/StreamTriad_par1.c.o
[ 33%] Building C object CMakeFiles/StreamTriad_par1.dir/timer.c.o
[ 37%] Linking C executable StreamTriad_par1
[ 37%] Built target StreamTriad_par1
Scanning dependencies of target StreamTriad_par3
[ 41%] Building C object CMakeFiles/StreamTriad_par3.dir/StreamTriad_par3.c.o
[ 45%] Building C object CMakeFiles/StreamTriad_par3.dir/timer.c.o
[ 50%] Linking C executable StreamTriad_par3
[ 50%] Built target StreamTriad_par3
Scanning dependencies of target StreamTriad
[ 54%] Building C object CMakeFiles/StreamTriad.dir/StreamTriad.c.o
[ 58%] Building C object CMakeFiles/StreamTriad.dir/timer.c.o
[ 62%] Linking C executable StreamTriad
[ 62%] Built target StreamTriad
Scanning dependencies of target StreamTriad_par4
[ 66%] Building C object CMakeFiles/StreamTriad_par4.dir/StreamTriad_par4.c.o
[ 70%] Building C object CMakeFiles/StreamTriad_par4.dir/timer.c.o
[ 75%] Linking C executable StreamTriad_par4
[ 75%] Built target StreamTriad_par4
Scanning dependencies of target StreamTriad_par6
[ 79%] Building C object CMakeFiles/StreamTriad_par6.dir/StreamTriad_par6.c.o
[ 83%] Building C object CMakeFiles/StreamTriad_par6.dir/timer.c.o
[ 87%] Linking C executable StreamTriad_par6
[ 87%] Built target StreamTriad_par6
Scanning dependencies of target StreamTriad_par2
[ 91%] Building C object CMakeFiles/StreamTriad_par2.dir/StreamTriad_par2.c.o
[ 95%] Building C object CMakeFiles/StreamTriad_par2.dir/timer.c.o
[100%] Linking C executable StreamTriad_par2
[100%] Built target StreamTriad_par2
````

### Run Output

````
Running StreamTriad -- running original serial code
Average runtime for stream triad loop is 0.029685 msecs

Running StreamTriad_par1 -- adding GPU work directives
Segmentation fault

Running StreamTriad_par2 -- adding GPU work directives with map
Average runtime for stream triad loop is 0.029553 secs

Running StreamTriad_par3 -- adding GPU structured data region
Average runtime for stream triad loop is 0.028421 msecs

Running StreamTriad_par4 -- dynamic data region
Average runtime for stream triad loop is 0.030913 msecs

${SOURCE_DIR}/run.sh: 18: ${SOURCE_DIR}/run.sh: [[: not found
Running StreamTriad_par6 -- only allocating arrays on GPU with omp_target_alloc
Segmentation fault

Running StreamTriad_par7 -- map alloc arrays on GPU
Segmentation fault

Running StreamTriad_par8 -- declare target arrays on GPU
Segmentation fault
````

*FAILED*

## ./OpenMP/Stencil/ Run Notes

### CMake Output

````
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Error at /usr/share/cmake-3.10/Modules/FindCUDA.cmake:682 (message):
  Specify CUDA_TOOLKIT_ROOT_DIR
Call Stack (most recent call first):
  CMakeLists.txt:24 (find_package)


-- Configuring incomplete, errors occurred!
See also "/tmp/tmpab85dapt/CMakeFiles/CMakeOutput.log".
````

*FAILED*

