/*
 *  Precision comparison of cos-1(1-x) and 2*sin-1sqrt(x/2).
 *  http://www.plunk.org/~hatch/rightway.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    return acos(1-x);
}

double func2(double x){
    return  2*asin(sqrt(.5*x));
}

int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<30; i++){
        x /= 10.;
        printf(" %.15e %.15e \n", func1(x), func2(x));
    }

    return 0;
}



/* solution proposé par llama3 :


double func1(double x){
    return 2*asin(sqrt(x/2));
}

double func2(double x){
    return 2*asin(sqrt(x/2));
}
( et ça marche )




Solution propose par claude-3-haiku

double func1(double x){
    return M_PI_2 - acos(1 - x);
}

double func2(double x){
    return 2 * asin(sqrt(x / 2));
}


}*/