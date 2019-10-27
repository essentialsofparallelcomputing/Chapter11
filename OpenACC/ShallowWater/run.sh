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

echo "Running ShallowWater"
./ShallowWater
echo ""
echo "Running ShallowWater_par1 -- adding compute region"
./ShallowWater_par1
echo ""
echo "Running ShallowWater_par2 -- adding dynamic data region"
./ShallowWater_par2
echo ""
echo "Running ShallowWater_par3 -- adding collapse clause"
./ShallowWater_par3
echo ""
echo "Running ShallowWater_par4 -- adding tile clause"
./ShallowWater_par4
echo ""
