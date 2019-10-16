#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"

void StreamTriad(double *restrict c, double *restrict a, double *restrict b, double scalar, int nsize);

int main(int argc, char *argv[]){

   int nsize = 20000000, ntimes=16;
   double *a, *b, *c;

#pragma omp target enter data map(alloc:a[0:nsize], b[0:nsize], c[0:nsize])

   struct timespec tstart;
   // initializing data and arrays
   double scalar = 3.0, time_sum = 0.0;
#pragma omp target
#pragma omp teams distribute parallel for
   for (int i=0; i<nsize; i++) {
      a[i] = 1.0;
      b[i] = 2.0;
   }

   for (int k=0; k<ntimes; k++){
      cpu_timer_start(&tstart);
      // stream triad loop 
#pragma omp target
#pragma omp teams distribute parallel for
      for (int i=0; i<nsize; i++){
         c[i] = a[i] + scalar*b[i];
      }
      time_sum += cpu_timer_stop(tstart);
   }

   printf("Average runtime for stream triad loop is %lf msecs\n", time_sum/ntimes);

#pragma omp target exit data map(delete:a[0:nsize], b[0:nsize], c[0:nsize])

   return(0);
}

void StreamTriad(double *restrict c, double *restrict a, double *restrict b, double scalar, int nsize){
   for (int i=0; i<nsize; i++){
      c[i] = a[i] + scalar*b[i];
   }
}