/*
 *  Precision comparison of sqrt(1+x)-1 and x / (sqrt(1+x)+1).
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return sqrt(1+x)-1;
}

double func2(double x){
    return  x / (sqrt(1+x)+1);
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<20; i++){
        x /= 10.;
        printf(" %.15e %.15e \n", func1(x), func2(x));
    }

    return 0;
}

