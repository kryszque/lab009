#include "backsubst.h"
#include <math.h>

/**
 
Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy*/
int backsubst(Matrix x, Matrix mat, Matrix b) {
    int i, j;

    // Sprawdzenie poprawności rozmiarów macierzy
    if (mat->r != mat->c || mat->r != b->r ||  x->r != b->r || x->c != 1) {
        return 2;  // Błąd nieprawidłowych rozmiarów macierzy
    }

    // Sprawdzenie czy ostatni element diagonalny jest bliski zeru
    if (fabs(mat->data[mat->r - 1][mat->r - 1]) < 1e-10) {
        return 1;  // Błąd dzielenia przez 0
    }

    // Rozwiązanie metodą podstawienia wstecznego
    for (i = mat->r - 1; i >= 0; i--) {
        // Obliczenie wartości x[i]
        x->data[i][0] = b->data[i][0];

        for (j = i + 1; j < mat->r; j++) {
            x->data[i][0] -= mat->data[i][j] x->data[j][0];
        }

        // Sprawdzenie czy element diagonalny jest bliski zeru
        if (fabs(mat->data[i][i]) < 1e-10) {
            return 1;  // Błąd dzielenia przez 0
        }

        // Podzielenie przez element diagonalny
        x->data[i][0] /= mat->data[i][i];
    }

    return 0;  // Wsteczne podstawienie zakończone sukcesem
}
