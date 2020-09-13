#include <stdio.h>
#include <openacc.h>
#include "timer.h"

int main(int argc, char *argv[]){

   int nsize = 20000000, ntimes=16;
   double* restrict a_d = acc_malloc(nsize * sizeof(double));
   double* restrict b_d = acc_malloc(nsize * sizeof(double));
   double* restrict c_d = acc_malloc(nsize * sizeof(double));

   struct timespec tstart;
   // initializing data and arrays
   const double scalar = 3.0;
   double time_sum = 0.0;
#pragma acc parallel loop deviceptr(a_d,b_d)
   for (int i=0; i<nsize; i++) {
      a_d[i] = 1.0;
      b_d[i] = 2.0;
   }

   for (int k=0; k<ntimes; k++){
      cpu_timer_start(&tstart);
      // stream triad loop 
#pragma acc parallel loop deviceptr(a_d,b_d,c_d)
      for (int i=0; i<nsize; i++){
         c_d[i] = a_d[i] + scalar*b_d[i];
      }
      time_sum += cpu_timer_stop(tstart);
   }

   printf("Average runtime for stream triad loop is %lf secs\n", time_sum/ntimes);

   acc_free(a_d);
   acc_free(b_d);
   acc_free(c_d);

   return(0);
}
