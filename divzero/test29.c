// repri l'exemple de cancellation benifique 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double func1(double x){
    double y = x - 1.0;
    double z = exp(y);
    
    
    return  log(z) / (z - 1.0);
}

double func2(double x){
    double y = x - 1.0;
    double z = exp(y);
 
    
    return  y / (z - 1.0);
}


int main(int argc, char **argv){
    double x=1.;

   
        printf(" %.15f %.15f \n", func1(x), func2(1.+x));
    

    return 0;
}
 // j'ai modifié le code pour que ça me retourne un nan dans la fonction 1 
