
// j'ai ramene ce code du td 3 de mr martel et j'ai juste remplacer la matrice par une matrice singuliere 

#include <stdio.h>
#include <math.h>

#define N 3 // Taille de la matrice A (N x N)
#define EPSILON 1e-10 // Petit nombre pour éviter les erreurs d'arrondi

// Fonction pour échanger deux lignes dans la matrice A
void swap_rows(double A[N][N], int i, int j) {
    for (int k = 0; k < N; k++) {
        double temp = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = temp;
    }
}

// Fonction pour résoudre le système A * x = b par l'algorithme du pivot de Gauss
int gauss_elimination(double A[N][N], double b[N], double x[N]) {
    // Elimination vers l'avant
    for (int i = 0; i < N; i++) {
        // Trouver le pivot pour cette colonne
        int max_row = i;
        for (int j = i + 1; j < N; j++) {
            if (fabs(A[j][i]) > fabs(A[max_row][i])) {
                max_row = j;
            }
        }
        
        /*// Vérifier si le pivot est nul
        if (fabs(A[max_row][i]) < EPSILON) {
            printf("La matrice est singulière. Impossible de résoudre le système.\n");
            return 0; // Sortir de la fonction avec un indicateur d'erreur
        }
        */
        // Echanger la ligne courante avec la ligne contenant le pivot
        if (max_row != i) {
            swap_rows(A, i, max_row);
            double temp = b[i];
            b[i] = b[max_row];
            b[max_row] = temp;
        }
        
        // Elimination
        for (int j = i + 1; j < N; j++) {
            double ratio = A[j][i] / A[i][i]; // Division par zéro possible ici
            for (int k = i; k < N; k++) {
                A[j][k] -= ratio * A[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }
    
    // Résolution en remontant
    for (int i = N - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i]; // Division par zéro possible ici
    }
    
    return 1; // Indiquer que la résolution s'est déroulée avec succès
}

int main() {
    // Matrice A et vecteur b
    double A[N][N] = {

    {1, 1, 1},

    {1, 1, 1},

    {1, 1, 1}

};
    double b[N] = {8, -11, -3};
    
    // Vecteur pour stocker la solution
    double x[N];
    
    // Résoudre le système
    if (!gauss_elimination(A, b, x)) {
        // Si la résolution échoue, quitter le programme
        return 1;
    }
    
    // Afficher la solution
    printf("La solution du système est:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
    
    return 0;
}


// resultats: x[0]=nan , x[1]=nan , x[2]=nan