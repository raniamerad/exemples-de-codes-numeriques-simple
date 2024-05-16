// test bete et facile que j'ai fais moi meme a remplacer si tu peux
#include <stdio.h>

int divide(int a, int b) {
    if (b == 0) {
        return a / b;  // Division par zéro peut se produire si b devient 0
    } else {
        return 0;
    }
}

int main() {
    int x = 10;
    int y = 0;
    int result = divide(x, y);
    printf("Result: %d\n", result);
    return 0;
}
/// resultat floating point exception 