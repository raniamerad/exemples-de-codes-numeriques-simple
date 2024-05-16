/*
 *  Compute Rump Equation
 *  http://link.springer.de/link/service/journals/00607/bibs/1066003/10660309.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fRump(float a, float b){
    float res;
    res = 333.75 * (b*b*b*b*b*b) + (a*a)*(11. * (a*a)*(b*b) - (b*b*b*b*b*b) - 121. * (b*b*b*b) - 2.) + 5.5 * (b*b*b*b*b*b*b*b) + a/(2*b);
    return res;
}

double dRump(double a, double b){
    double res;
    res = 333.75 * (b*b*b*b*b*b) + (a*a)*(11. * (a*a)*(b*b) - (b*b*b*b*b*b) - 121. * (b*b*b*b) - 2.) + 5.5 * (b*b*b*b*b*b*b*b) + a/(2*b);
    return res;
}


int main(int argc, char **argv){
    float a,b;
    a = 77617.;
    b = 33096.;
    
    printf("Rump example (float): %e\n", fRump(a,b));
    printf("Rump example (double): %e\n", dRump(a,b));

    return 0;
}

