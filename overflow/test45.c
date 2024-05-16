/*
 *  Precision comparison of sinh(x) and expm1(x) * (expm1(x)+2) / (expm1(x)+1) / 2
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return expm1(x) * (expm1(x)+2) / (expm1(x)+1) / 2;
}

double func2(double x){
    double u = expm1(x);
    return .5 * u / (u+1.) * (u+2.);
}

double func3(double x){
    return sinh(x);
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<10; i++){
        x += 50;
        printf(" %.15e %.15e %.15e \n", func1(x), func2(x), func3(x));
    }

    return 0;
}
