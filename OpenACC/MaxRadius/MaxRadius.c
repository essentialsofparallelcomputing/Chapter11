#include <stdio.h>
#include <math.h>

#pragma acc routine
double FindMaxRadius(int ncells, double* restrict x, double* restrict y);

int main(int argc, char *argv[]){
   int ncells = 20000000;

   double *x, *y;
#pragma acc enter data create (x[0:ncells], y[0:ncells])

#pragma acc parallel loop present(x[0:ncells], y[0:ncells])
   for (int ic=0; ic<ncells; ic++) {
      x[ic] = (double)(ic+1);
      y[ic] = (double)(ncells-ic);
   }

   double MaxRadius = FindMaxRadius(ncells, x, y);
#pragma acc exit data delete(x[0:ncells], y[0:ncells])

// printf("Maximum Radius is %lf\n",MaxRadius);
}

double FindMaxRadius(int ncells, double* restrict x, double* restrict y){
   double max_radius = -1.0e30;
//#pragma acc parallel loop reduction(max:max_radius)
   for (int ic=0; ic<ncells ; ic++) {
      double radius = sqrt(x[ic]*x[ic] + y[ic]*y[ic]);
      if (radius > max_radius) max_radius = radius;
   }
   return(max_radius);
}
