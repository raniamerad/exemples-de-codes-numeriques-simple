/*
 *  Exemple of a cancellation which is beneficial at the end ! 
 *  http://www.eecs.berkeley.edu/~wkahan/JAVAhurt.pdf
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x){
    double y = x - 1.0;
    double z = exp(y);
    
    if (z == 1) 
        return z;
    
    return  log(z) / (z - 1.0);
}

double func2(double x){
    double y = x - 1.0;
    double z = exp(y);
    
    if (z == 1) 
        return z;
    
    return  y / (z - 1.0);
}


int main(int argc, char **argv){
    double x=1.;

    for(int i=0; i<10; i++){
        x /= 10.;
        printf(" %.15f %.15f \n", func1(1.+x), func2(1.+x));
    }

    return 0;
}

