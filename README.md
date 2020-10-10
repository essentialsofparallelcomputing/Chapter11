# Chapter 11 Directive-based GPU programming
This is from Chapter 11 of Parallel and High Performance Computing, Robey and Zamora,
Manning Publications, available at http://manning.com

The book may be obtained at
   http://www.manning.com/?a_aid=ParallelComputingRobey

Copyright 2019-2020 Robert Robey, Yuliana Zamora, and Manning Publications
Emails: brobey@earthlink.net, yzamora215@gmail.com

See License.txt for licensing information.

# OpenACC Stream Triad (Book: listings 11.1 - 11.3, 11.5 - 11.7)
   Build with cmake or make
      cd OpenACC/StreamTriad
      mkdir build && cd build
      cmake .. && make
   Run with
      ./StreamTriad_kern1-
      ./StreamTriad_par1-

# OpenACC Mass sum (Book: listing 11.4)
   Build with cmake
      cd OpenACC/mass_sum
      mkdir build && cd build
      cmake .. && make
   Run with
      ./mass_sum

# OpenACC Stencil (Book: listings 11.8 - 11.10)
   Build with cmake
      cd OpenACC/Stencil
      mkdir build && cd build
      cmake .. && make
   Run with
      ./Stencil_par1-

# OpenMP Stream Triad (Book: listings 11.12-11.18)
   Build with cmake or make
      cd OpenMP/StreamTriad
      mkdir build && cd build
      cmake .. && make
   Run with
      ./StreamTriad_par1-

# OpenMP Stencil (Book: listing 11.19-11.21)
   Build with cmake
      cd OpenMP/Stencil
      mkdir build && cd build
      cmake .. && make
   Run with
      ./Stencil_par1-
