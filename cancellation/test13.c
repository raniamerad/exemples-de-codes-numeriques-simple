/*
 *  Precision comparison of (1+x)^2-1 and x * (2 + x).
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return (1+x)*(1+x)-1;
}

double func2(double x){
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



/*solution proposée par llama3 : 
double func1(double x){
    return 2*x + x*x;
}
 solution propose par claude :
 en gros reproduire la meme fonction  :
 double func1(double x){
    return  x * (2 + x);
} 
 */