#include <stdio.h>

int main() {
    int i;
    int x=5;
    for (i = 5; i >= -1; i--) {
        int result = x / i;  // Division par zéro
        printf("Result: %d\n", result);
    }
    return 0;
}
/// resultat floating point exception (core dumped)