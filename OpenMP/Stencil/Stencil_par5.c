#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "malloc2D.h"
#include "timer.h"

#define SWAP_PTR(xnew,xold,xtmp) (xtmp=xnew, xnew=xold, xold=xtmp)

int main(int argc, char *argv[])
{
   struct timespec tstart_cpu, tstop_cpu;
   double cpu_time;
   int imax=2002, jmax = 2002;
   int niter=1000, nburst=100;

   double** restrict xtmp;
   double** restrict x    = malloc2D(jmax, imax);
   double** restrict xnew = malloc2D(jmax, imax);

#pragma omp target enter data map(to:x[0:jmax][0:imax], xnew[0:jmax][0:imax])

#pragma omp target teams
   {
#pragma omp distribute
      for (int j = 0; j < jmax; j++){
#pragma omp parallel for simd
         for (int i = 0; i < imax; i++){
            xnew[j][i] = 0.0;
            x[j][i]    = 5.0;
         }
      }

#pragma omp distribute
      for (int j = jmax/2 - 5; j < jmax/2 + 5; j++){
#pragma omp parallel for simd
         for (int i = imax/2 - 5; i < imax/2 -1; i++){
            x[j][i] = 400.0;
         }
      }
   }

   for (int iter = 0; iter < niter; iter+=nburst){

      for (int ib = 0; ib < nburst; ib++){
         cpu_timer_start(&tstart_cpu);
#pragma omp target teams distribute
         for (int j = 1; j < jmax-1; j++){
#pragma omp parallel for simd schedule(static,1)
            for (int i = 1; i < imax-1; i++){
               xnew[j][i] = ( x[j][i] + x[j][i-1] + x[j][i+1] + x[j-1][i] + x[j+1][i] )/5.0;
            }
         }
         cpu_time += cpu_timer_stop(tstart_cpu);

         SWAP_PTR(xnew, x, xtmp);
      }

      printf("Iter %d\n",iter+nburst);
   }

#pragma omp target exit data map(from:x[0:jmax][0:imax], xnew[0:jmax][0:imax])

   free(x);
   free(xnew);

   printf("Timing is %f\n",cpu_time);
}
