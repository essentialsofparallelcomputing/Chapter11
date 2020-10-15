#!/bin/sh

echo "Running StreamTriad -- running original serial code"
./StreamTriad
echo ""
echo "Running StreamTriad_par1 -- adding GPU work directives"
./StreamTriad_par1
echo ""
echo "Running StreamTriad_par2 -- adding GPU work directives with map"
./StreamTriad_par2
echo ""
echo "Running StreamTriad_par3 -- adding GPU structured data region"
./StreamTriad_par3
echo ""
echo "Running StreamTriad_par4 -- dynamic data region"
./StreamTriad_par4
echo ""
if [ -x ./StreamTriad_par5 ]; then
   echo "Running StreamTriad_par5 -- only allocating arrays on GPU with cudaMalloc"
   ./StreamTriad_par5
   echo ""
fi
echo "Running StreamTriad_par6 -- only allocating arrays on GPU with omp_target_alloc"
./StreamTriad_par6
echo ""
echo "Running StreamTriad_par7 -- map alloc arrays on GPU"
./StreamTriad_par7
echo ""
echo "Running StreamTriad_par8 -- declare target arrays on GPU"
./StreamTriad_par8
