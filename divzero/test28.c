// code qui calcul l'expo  bon j'ai modifié 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double approx(double x){
    int n = 100;

    double sum  = 0.0;
    double term = 1.0;
    for (int i = 0; sum <50; i++) {  // normalement for (int i = 1; sum != sum + term; i++)
        sum  = sum + term;
        term = term * x / i;
    }
    return sum;
}



int main(){
    int val[7]={0,1,50,100,-100,-1000,-10000};
    for (int i = 0; i<7; i++) {
        printf("%e %e \n", approx(val[i]), exp(val[i]));
    }

    return 0;
}

/*resultat : -nan 1.000000e+00 
inf 2.718282e+00 
inf 5.184706e+21 
inf 2.688117e+43 
-nan 3.720076e-44 
-nan 0.000000e+00 
-nan 0.000000e+00 */ 