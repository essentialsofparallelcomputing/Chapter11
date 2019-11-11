#include <stdio.h>
#include <math.h>
#include <openacc.h>

int main(int argc, char *argv[]){
   int ncells = 20000000;
   double* restrict x = acc_malloc(ncells * sizeof(double));
   double* restrict y = acc_malloc(ncells * sizeof(double));

   double MaxRadius = -1.0e30;
#pragma acc parallel deviceptr(x, y)
   {
#pragma acc loop
      for (int ic=0; ic<ncells; ic++) {
         x[ic] = (double)(ic+1);
         y[ic] = (double)(ncells-ic);
      }

#pragma acc loop reduction(max:MaxRadius)
      for (int ic=0; ic<ncells ; ic++) {
         double radius = sqrt(x[ic]*x[ic] + y[ic]*y[ic]);
         if (radius > MaxRadius) MaxRadius = radius;
      }
   }
   printf("Maximum Radius is %lf\n",MaxRadius);

   acc_free(x);
   acc_free(y);
}
