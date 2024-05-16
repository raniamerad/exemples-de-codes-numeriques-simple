/*
 *  Precision comparison of tanh(x) and expm1(2*x) / (expm1(2*x) + 2).
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return expm1(2*x) / (expm1(2*x) + 2);
}

double func2(double x){
    return tanh(x);
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<10; i++){
        x *= 10;
        printf(" %.15e %.15e \n", func1(x), func2(x));
    }

    return 0;
}
