/*
 *  Precision comparison of exp(x)-1 and expm1(x)
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return exp(x)-1.;
}

double func2(double x){
    return  tanh(x/2)*(exp(x)+1);
}

double func3(double x){
    double u = exp(x);
    if (u == 1.)
        return x;
    if (u-1. == -1.)
        return -1.;
    return (u-1.)*x/log(u); 
}

double func4(double x){
    return  expm1(x);
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<30; i++){
        x /= 10.;
        printf(" %.15e %.15e %.15e %.15e \n", func1(x), func2(x), func3(x), func4(x));
    }

    return 0;
}

