/*
 *  Precision comparison of angle computation between unit vectors ( cos-1(u dot v) )
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double *u, double *v, int n){
    double u_dot_v=0;
    double nu=0, nv=0;

    for (int i=0; i<n; i++){
        u_dot_v += u[i] * v[i];
        nu = u[i] * u[i];
        nv = v[i] * v[i];    
    }
    nu = sqrt(nu);
    nv = sqrt(nv);

    // can generate argument slightly larger than 1 !
    return acos(u_dot_v/(nu*nv)); 
}

double func2(double *u, double *v, int n){
    double u_dot_v=0;

    for (int i=0; i<n; i++)
        u_dot_v += u[i] * v[i];

    return  x * (2 + x);
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<20; i++){
        x /= 10.;
        printf(" %.15e %.15e \n", func1(x), func2(x));
    }

    return 0;
}

