//exemple div par zero dans les fonctions trigonometrique 



#include <stdio.h>
#include <math.h>

int main() {
    double x = 0;
    double y = 1.0;
    double angle = atan2(y, x);  // Calcul de l'angle à partir des coordonnées (x, y)
    double result = cos(y)/sin(x); // Division de sin(angle) par cos(angle)
    printf("Result: %lf\n", result);
    return 0;
}


/// resultat de ce code  = inf