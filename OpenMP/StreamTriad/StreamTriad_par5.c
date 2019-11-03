#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>
#include "timer.h"

int main(int argc, char *argv[]){

   int nsize = 20000000, ntimes=16;

   double *a, *b, *c;
   cudaMalloc((void *)&a,nsize*sizeof(double));
   cudaMalloc((void *)&b,nsize*sizeof(double));
   cudaMalloc((void *)&c,nsize*sizeof(double));

#pragma target enter data use_device_ptr(a, b, c)

   struct timespec tstart;
   // initializing data and arrays
   double scalar = 3.0, time_sum = 0.0;
#pragma omp target teams distribute parallel for simd is_device_ptr(a, b)
   for (int i=0; i<nsize; i++) {
      a[i] = 1.0;
      b[i] = 2.0;
   }

   for (int k=0; k<ntimes; k++){
      cpu_timer_start(&tstart);
      // stream triad loop 
#pragma omp target teams distribute parallel for simd is_device_ptr(a, b, c)
      for (int i=0; i<nsize; i++){
         c[i] = a[i] + scalar*b[i];
      }
      time_sum += cpu_timer_stop(tstart);
   }

   printf("Average runtime for stream triad loop is %lf msecs\n", time_sum/ntimes);

#pragma target exit data use_device_ptr(a, b, c)

   cudaFree(a);
   cudaFree(b);
   cudaFree(c);

   return(0);
}
