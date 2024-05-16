// fonction pas complique
#include <stdio.h>
#include <math.h>
#define _Pi 3.1415927
double complexFunction(double x) {
    double result = 0.0;
    if (x > 0) {
        double angle = atan(x);
        result = cos(angle) / sin(angle - _Pi/2);  // Division par zéro si sin(angle - π/2) est proche de 0
    } else {
        result = exp(x) / (x + 1);  // Division par zéro si x = -1
    }
    return result;
}

int main() {
    double x = -1.0;
    double result = complexFunction(x);
    printf("Result: %lf\n", result);
    return 0;
}


//resultat produit : inf si x=-1

