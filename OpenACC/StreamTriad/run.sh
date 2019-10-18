#!/bin/sh
#export PGI_ACC_NOTIFY=1
export PGI_ACC_TIME=1


# GCC environment variables
#export GOMP_DEBUG=1
#export ACC_DEVICE_NUM=#
#export ACC_DEVICE_TYPE=[host|nvidia]

echo "Running StreamTriad"
./StreamTriad
echo ""
echo "Running StreamTriad_kern1"
./StreamTriad_kern1
echo ""
echo "Running StreamTriad_kern2"
./StreamTriad_kern2
echo ""
echo "Running StreamTriad_kern2"
./StreamTriad_kern2
echo ""
echo "Running StreamTriad_par1"
./StreamTriad_par1
echo ""
echo "Running StreamTriad_par2"
./StreamTriad_par2
echo ""
echo "Running StreamTriad_par3"
./StreamTriad_par3
echo ""
echo "Running StreamTriad_par4"
./StreamTriad_par4
