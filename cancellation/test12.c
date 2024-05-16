/*
 *  Compute roots of a quadratic polynomial using 3 differents way's from the less safe to the safest
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quadratic1(double a, double b, double c, double *root1, double *root2){
    double discriminant;

    discriminant = b*b - 4*a*c;
    *root1 = -b + sqrt(discriminant) / (2*a);
    *root2 = -b - sqrt(discriminant) / (2*a);
}

void quadratic2(double a, double b, double c, double *root1, double *root2){
    double discriminant;

    discriminant = b*b - 4*a*c;
    if ((a==0)||(discriminant<0)){
        printf("No real roots\n");
        exit(-1);
    }

    *root1 = -b +  sqrt(discriminant) / (2*a);
    *root2 = -b -  sqrt(discriminant) / (2*a);
}

void quadratic3(double a, double b, double c, double *root1, double *root2){
    double discriminant,q;

    discriminant = b*b - 4*a*c;
    if ((a==0)||(discriminant<0)){
        printf("No real roots\n");
        exit(-1);
    }


    if (b > 0) q = -0.5 * (b + sqrt(discriminant));
    else       q = -0.5 * (b - sqrt(discriminant));
    *root1 = q / a;
    *root2 = c / q;
}


int main(int argc, char **argv){
    double a,b,c,r1,r2;
    a = 1.;
    b = -3000000.;
    c = 2.;

    quadratic1(a,b,c,&r1,&r2);
    printf(" quadratic1:  %e  %e\n", r1, r2);

    quadratic2(a,b,c,&r1,&r2);
    printf(" quadratic2:  %e  %e\n", r1, r2);

    quadratic3(a,b,c,&r1,&r2);
    printf(" quadratic3:  %e  %e\n", r1, r2);

    return 0;
}

