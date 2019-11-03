#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

   double *a, *b, *c;

#pragma omp target enter data use_device_ptr(a, b, c)

#pragma omp target exit data use_device_ptr(a, b, c)

   return(0);
}
