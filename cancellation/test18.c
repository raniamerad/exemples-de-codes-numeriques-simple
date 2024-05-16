/*
 *  Compute the e^x using the Taylor series:
 *  e^x = 1 + x + x^2/2! + x^3/3! + ...
 *  and also using Math.exp. Catastrophic cancelation
 *  occurs if x is a large negative number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double approx(double x){
    int n = 100;

    double sum  = 0.0;
    double term = 1.0;
    for (int i = 1; sum != sum + term; i++) {
        sum  = sum + term;
        term = term * x / i;
    }
    return sum;
}

int val[7]={0,1,50,-1,-10,-30,-50};

int main(int argc, char **argv){
    for (int i = 0; i<7; i++) {
        printf("%e %e \n", approx(val[i]), exp(val[i]));
    }

    return 0;
}

