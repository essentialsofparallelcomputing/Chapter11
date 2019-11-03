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
echo "Running StreamTriad_par3 -- adding GPU data region"
./StreamTriad_par3
echo ""
echo "Running StreamTriad_par4 -- adding GPU allocation"
./StreamTriad_par4
echo ""
echo "Running StreamTriad_par5 -- only allocating arrays on GPU with cudaMalloc"
./StreamTriad_par5
echo ""
echo "Running StreamTriad_par6 -- map alloc arrays on GPU"
./StreamTriad_par6
echo ""
echo "Running StreamTriad_par7 -- declare target arrays on GPU"
./StreamTriad_par7
