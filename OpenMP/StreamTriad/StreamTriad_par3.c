#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"

int main(int argc, char *argv[]){

   int nsize = 20000000, ntimes=16;
   double* restrict a = malloc(nsize * sizeof(double));
   double* restrict b = malloc(nsize * sizeof(double));
   double* restrict c = malloc(nsize * sizeof(double));

   struct timespec tstart;
   // initializing data and arrays
   double scalar = 3.0, time_sum = 0.0;

#pragma omp target data map(to:a[0:nsize], b[0:nsize], c[0:nsize])
   {
#pragma omp target teams distribute parallel for simd
      for (int i=0; i<nsize; i++) {
         a[i] = 1.0;
         b[i] = 2.0;
      }

      for (int k=0; k<ntimes; k++){
         cpu_timer_start(&tstart);
         // stream triad loop 
#pragma omp target teams distribute parallel for simd
         for (int i=0; i<nsize; i++){
            c[i] = a[i] + scalar*b[i];
         }
         time_sum += cpu_timer_stop(tstart);
      }

   } // #pragma omp target data map(from:c[0:nsize])

   printf("Average runtime for stream triad loop is %lf msecs\n", time_sum/ntimes);

   free(a);
   free(b);
   free(c);

   return(0);
}
