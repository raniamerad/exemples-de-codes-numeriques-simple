/*
 *  Precision comparison of ln(1+x) and log1p(x).
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return log(1+x);
}

double func2(double x){
    return  2*atanh(x/(x+2));
}

double func3(double x){
    double u = 1.+x;
    if (u == 1.)
        return x;
    else
        return log(u)*x/(u-1.);
}

double func4(double x){
    return  log1p(x);
}


int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<30; i++){
        x /= 10.;
        printf(" %.15e %.15e %.15e %.15e \n", func1(x), func2(x), func3(x), func4(x));
    }

    return 0;
}

