#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// compute f(x)  = (1 - cos x) / x^2 in floating point
double fl(double x) {
    double a = cos(x);
    double b = 1.0 - a;
    double c = b / (x*x);
    return c;
}

// compute f(x)  = (1 - cos x) / x^2 in floating point
// compiler may produce more accurate results by using more precision than
// IEEE requires
double fl2(double x) {
    return (1.0 - cos(x)) / (x*x);
}


double f(double x) {
    return 2 * sin(x/2) * sin(x/2) / (x*x);
}



int main(int argc, char **argv)
{
    int N = 1000;

    // x-interval to plot
    double x0 = 1e-300;
    double x1 = 1e-300;

    int nbytes = N*sizeof(double); 
    double *vals1 = (double *)malloc(nbytes);
    double *vals2 = (double *)malloc(nbytes);
    double *vals3 = (double *)malloc(nbytes);

    for (int i = 0; i <= N; i++) {
        double x =  x0 + ((x1 - x0) * i) / N;
        vals1[i] = fl(x);
        vals2[i] = fl2(x);
        vals3[i] = f(x);
    
printf(" result val1=%lf , val2=%lf , val3= %lf /n",vals1[i],vals2[i],vals3[i]);
    }
    return 0;
}


// resultat est nan pour x= x1 = 1e-300;
