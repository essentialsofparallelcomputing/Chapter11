#!/bin/sh

echo "Running Stencil -- running original serial code"
./Stencil
echo ""
echo "Running Stencil_par1 -- adding GPU work directives"
./Stencil_par1
echo ""
echo "Running Stencil_par2 -- adding GPU work directives with map"
./Stencil_par2
