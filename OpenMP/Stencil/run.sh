#!/bin/sh

echo "Running Stencil -- running original serial code"
./Stencil
echo ""
echo "Running Stencil_par1 -- adding GPU work directives"
./Stencil_par1
echo ""
echo "Running Stencil_par2 -- adding GPU work directives with map"
./Stencil_par2
echo ""
echo "Running Stencil_par3 -- adding collapse clause"
./Stencil_par3
echo ""
echo "Running Stencil_par4 -- splitting parallel loop levels"
./Stencil_par4
echo ""
echo "Running Stencil_par5 -- splitting parallel loop levels with schedule(static,1)"
./Stencil_par5
if [[ -x ./Stencil_par6 ]]; then
   echo "Running Stencil_par6 -- using the new loop directive"
   ./Stencil_par6
   echo ""
else
   echo "Compiler does not yet support the new loop directive added in OpenMP 5.0"
fi

