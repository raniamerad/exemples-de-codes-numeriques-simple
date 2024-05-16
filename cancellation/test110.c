/*
 *  Compute Triangle Area using Heron's formula
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double heron1(double a, double b, double c){
    double s, area;

    s =  (a + b + c) / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    return area;
}

double heron2(double a, double b, double c){
    double area;
    double x1,x2,x3;

    x1 = fmax(a, fmax(b,c));
    x3 = fmin(a, fmin(b,c));
    x2 = a+b+c-x1-x3;

    if (x1 > (x2+x3)){
        printf("illegal triangle\n");
        return (-1);
    }
    area = 1./4. * sqrt((a+(b+c)) * (c-(a-b)) * (c+(a-b)) *(a+(b-c)));

    return area;
}



int main(int argc, char **argv){
    float a,b,c;
    a = 77617.;
    b = 77617.;
    c = 1.01233995;
    
    printf("Area with Heron1: %e\n", heron1(a,b,c));
    printf("Area with Heron2: %e\n", Heron2(a,b,c));

    return 0;
}

