#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "timer.h"
#include "ShallowWater.h"

/*********************************************************************************************
 * WAVE -- 2D Shallow Water Equation Model
 *                            Bob Robey, Los Alamos National Laboratory
 * ******************************************************************************************/

//define macro for squaring a number
#define SQ(x) ((x)*(x))

#define SWAP_PTR(xnew,xold,xtmp) (xtmp=xnew, xnew=xold, xold=xtmp)

/* Memory allocation routines */
double **malloc2D(int m, int n);

int main(int argc, char *argv[])
{
  int      nx = 500, ny = 200;
  int      ntimes = 2000, nburst = 100;
  double   deltaX=1.0, deltaY=1.0;         //size of cell
  double   g = 9.80;                           // gravitational constant
  double   deltaT = 0.05;                       //hardwired timestep
  double   time=0.0;                           //computer simulation time
  double   totaltime;   //variables to calculate time taken for the program to run
  struct   timespec starttime;
  double   TotalMass, origTM;    //variables for checking conservation of mass
  
  /* allocate the memory dynamically for the matrix */
  // state variables
  double** restrict H = malloc2D(ny+2, nx+2);
  double** restrict U = malloc2D(ny+2, nx+2);
  double** restrict V = malloc2D(ny+2, nx+2);

  double** restrict Hnew = malloc2D(ny+2, nx+2);
  double** restrict Unew = malloc2D(ny+2, nx+2);
  double** restrict Vnew = malloc2D(ny+2, nx+2);

  // half-step arrays
  double** restrict Hx = malloc2D(ny, nx+1);
  double** restrict Ux = malloc2D(ny, nx+1);
  double** restrict Vx = malloc2D(ny, nx+1);

  double** restrict Hy = malloc2D(ny+1, nx);
  double** restrict Uy = malloc2D(ny+1, nx);
  double** restrict Vy = malloc2D(ny+1, nx);

  double** restrict temp;

  /*initialize matrix*/
  
  #pragma acc parallel loop
  for(int j=0;j<=ny+1;j++){
    for(int i=0;i<=nx+1;i++){
      H[j][i]=2.0;
      U[j][i]=0.0;
      V[j][i]=0.0;
    }
    for(int i=0;i<=(nx+1)/2;i++){
      H[j][i]=10.0 - ((10.0 - 2.0)/ (double)((nx+1)/2))*(double)(i);
    }
  }

  origTM=0.0;
  #pragma acc parallel loop
  for(int j=1;j<=ny;j++){
    for(int i=1;i<=nx;i++){
        origTM+=H[j][i];
    }
  }
  
  //print iteration info
  printf("Iteration:%5.5d, Time:%f, Timestep:%f Total mass:%f\n", 0, time, deltaT, origTM);

  cpu_timer_start(&starttime);

  /* run the simulation for given number of iterations */
  for (int n = 0; n < ntimes; ) {

    for (int ib=0; ib<nburst; ib++){

      //set boundary conditons
#pragma acc parallel loop
      for(int j=1;j<=ny;j++){
        H[j][0]=H[j][1];
        U[j][0]=-U[j][1];
        V[j][0]=V[j][1];
        H[j][nx+1]=H[j][nx];
        U[j][nx+1]=-U[j][nx];
        V[j][nx+1]=V[j][nx];
      }
#pragma acc parallel loop
      for(int i=0;i<=nx+1;i++){
        H[0][i]=H[1][i];
        U[0][i]=U[1][i];
        V[0][i]=-V[1][i];
        H[ny+1][i]=H[ny][i];
        U[ny+1][i]=U[ny][i];
        V[ny+1][i]=-V[ny][i];
      }
    
      //set timestep
      // We should calculate a timestep here based on SQ(c)=g*h and not let a wave
      // cross a cell. But it does not vary much so a constant timestep is used for now

      //first pass
      //x direction
#pragma acc parallel loop
      for (int j = 0; j < ny; j++) {
        for (int i = 0; i<=nx;i++) {
          //density calculation
          Hx[j][i]=0.5*(H[j+1][i+1]+H[j+1][i  ]) - deltaT/(2.0*deltaX)*
                              (U[j+1][i+1]-U[j+1][i  ]);
          //momentum x calculation
          Ux[j][i]=0.5*(U[j+1][i+1]+U[j+1][i  ]) - deltaT/(2.0*deltaX)*
                             ((SQ(U[j+1][i+1])/H[j+1][i+1] + 0.5*g*SQ(H[j+1][i+1])) -
                              (SQ(U[j+1][i  ])/H[j+1][i  ] + 0.5*g*SQ(H[j+1][i  ])));
          //momentum y calculation
          Vx[j][i]=0.5*(V[j+1][i+1]+V[j+1][i  ]) - deltaT/(2.0*deltaX)*
                             ((U[j+1][i+1]*V[j+1][i+1]/H[j+1][i+1]) -
                              (U[j+1][i  ]*V[j+1][i  ]/H[j+1][i  ]));
        }
      }
    
    
      //y direction
#pragma acc parallel loop
      for(int j = 0; j<=ny; j++){
        for(int i=0; i<nx; i++){
          //density calculation
          Hy[j][i]=0.5*(H[j+1][i+1]+H[j  ][i+1]) - deltaT/(2.0*deltaY)*
                              (V[j+1][i+1]-V[j  ][i+1]);
          //momentum x calculation
          Uy[j][i]=0.5*(U[j+1][i+1]+U[j  ][i+1]) - deltaT/(2.0*deltaY)*
                             ((V[j+1][i+1]*U[j+1][i+1]/H[j+1][i+1]) -
                              (V[j  ][i+1]*U[j  ][i+1]/H[j  ][i+1]));
          //momentum y calculation
          Vy[j][i]=0.5*(V[j+1][i+1]+V[j  ][i+1]) - deltaT/(2.0*deltaY)*
                             ((SQ(V[j+1][i+1])/H[j+1][i+1] + 0.5*g*SQ(H[j+1][i+1])) -
                              (SQ(V[j  ][i+1])/H[j  ][i+1] + 0.5*g*SQ(H[j  ][i+1])));
        }
      }

      //second pass
#pragma acc parallel loop
      for (int j = 1; j <=ny; j++) {
        for (int i = 1; i<=nx;i++) {
          //density calculation
          Hnew[j][i] = H[j][i] - (deltaT/deltaX)*(Ux[j-1][i  ]-Ux[j-1][i-1])
                                     - (deltaT/deltaY)*(Vy[j  ][i-1]-Vy[j-1][i-1]);
          //momentum x calculation
          Unew[j][i] = U[j][i] - (deltaT/deltaX)*
                                  ((SQ(Ux[j-1][i  ])/Hx[j-1][i  ] +0.5*g*SQ(Hx[j-1][i  ])) -
                                   (SQ(Ux[j-1][i-1])/Hx[j-1][i-1] +0.5*g*SQ(Hx[j-1][i-1])))
                               - (deltaT/deltaY)*
                                  ((Vy[j  ][i-1]*Uy[j  ][i-1]/Hy[j  ][i-1]) -
                                   (Vy[j-1][i-1]*Uy[j-1][i-1]/Hy[j-1][i-1]));
          //momentum y calculation
          Vnew[j][i] = V[j][i] - (deltaT/deltaX)*
                                  ((Ux[j-1][i  ]*Vx[j-1][i  ]/Hx[j-1][i  ]) -
                                   (Ux[j-1][i-1]*Vx[j-1][i-1]/Hx[j-1][i-1]))
                               - (deltaT/deltaY)*
                                  ((SQ(Vy[j  ][i-1])/Hy[j  ][i-1] +0.5*g*SQ(Hy[j  ][i-1])) -
                                   (SQ(Vy[j-1][i-1])/Hy[j-1][i-1] +0.5*g*SQ(Hy[j-1][i-1])));
        }
      }
    
      SWAP_PTR(H, Hnew, temp);

    } // burst loop
      
    TotalMass=0.0;
#pragma acc parallel loop reduction(+:TotalMass)
    for(int j=1;j<=ny;j++){
      for(int i=1;i<=nx;i++){
          //if (isnan(H[j][i])) {
          //  printf("Error -- H[%d][%d]=%f\n",i,j,H[j][i]);
          //}
          TotalMass+=H[j][i];
      }
    }

    if(((fabs(TotalMass-origTM)>1.0E-6)||isnan(TotalMass))&&check==1){
       printf("Conservation of mass\nMass difference:%e\n", TotalMass-origTM);
       printf("Problem occured on iteration %5.5d at time %f.\n", n, time);
       //exit(0);
    }
    time+=deltaT;
    n+=nburst;

    //print iteration info
    if (n%100 == 0) printf("Iteration:%5.5d, Time:%f, Timestep:%f Total mass:%f\n", n, time, deltaT, TotalMass);

  }  // End of iteration loop
  
  /* Compute the average time taken/processor */
  totaltime = cpu_timer_stop(starttime);
  
  /* Print the total time taken */
  printf(" Flow finished in %lf seconds\n",totaltime);//*/

  // Free memory allocated with malloc2D call
  free(H);
  free(U);
  free(V);
  free(Hnew);
  free(Unew);
  free(Vnew);
  free(Hx);
  free(Ux);
  free(Vx);
  free(Hy);
  free(Uy);
  free(Vy);
  
  exit(0);
}
