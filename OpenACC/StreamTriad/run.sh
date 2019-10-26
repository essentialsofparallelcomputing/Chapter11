#!/bin/sh
#export PGI_ACC_NOTIFY=1
# where the argument is a bit mask
# 1  - kernels launch
# 2  - data transfers
# 4  - sync operations
# 8  - region entry/exit
# 16 - data allocation/free
export PGI_ACC_TIME=1
#export PGI_ACC_DEBUG=1
#export PGI_ACC_SYNCHRONOUS=1


# Possible GCC environment variables
#export GOMP_DEBUG=1
#export ACC_DEVICE_NUM=#
#export GOMP_OPENACC_DIM=<gang:worker:vector>
#    e.g. 5120:32:32, or -:32:32 where the dash indicates use compiler default for device.
#    can also be specified as a compiler flag
#export ACC_DEVICE_TYPE=[host|nvidia]

echo "Running StreamTriad"
./StreamTriad
echo ""
echo "Running StreamTriad_kern1 -- kernel region, but compiler fails to parallelize loop"
./StreamTriad_kern1
echo ""
echo "Running StreamTriad_kern2 -- kernel region, loop is parallelized"
./StreamTriad_kern2
echo ""
echo "Running StreamTriad_kern3 -- data region eliminates data transfers"
./StreamTriad_kern3
echo ""
echo "Running StreamTriad_par1 -- parallel loop region"
./StreamTriad_par1
echo ""
echo "Running StreamTriad_par2 -- added structured data region"
./StreamTriad_par2
echo ""
echo "Running StreamTriad_par3 -- added dynamic data region"
./StreamTriad_par3
echo ""
echo "Running StreamTriad_par4 -- allocating data only on device"
./StreamTriad_par4
