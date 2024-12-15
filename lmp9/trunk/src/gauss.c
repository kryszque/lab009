#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k;
    double factor;

    // Sprawdzenie poprawności rozmiarów macierzy
    if (mat->r != b->r || b->c != 1) {
        return 2;  // Nieprawidłowe rozmiary macierzy
    }

    // Eliminacja Gaussa z metodą częściowego wyboru elementu głównego
    for (i = 0; i < mat->r - 1; i++) {
        // Znajdź wiersz z maksymalną wartością bezwzględną w aktualnej kolumnie
        int max_row = i;
        for (k = i + 1; k < mat->r; k++) {
            if (fabs(mat->data[k][i]) > fabs(mat->data[max_row][i])) {
                max_row = k;
            }
        }

        // Zamień wiersze, jeśli znaleziono większy element
        if (max_row != i) {
            // Zamiana wierszy macierzy współczynników
            for (j = i; j < mat->c; j++) {
                double temp = mat->data[i][j];
                mat->data[i][j] = mat->data[max_row][j];
                mat->data[max_row][j] = temp;
            }
            
            // Zamiana wierszy macierzy wyrazów wolnych
            double temp_b = b->data[i][0];
            b->data[i][0] = b->data[max_row][0];
            b->data[max_row][0] = temp_b;
        }

        // Sprawdzenie czy element diagonalny jest bliski zeru
        if (fabs(mat->data[i][i]) < 1e-10) {
            return 1;  // Macierz osobliwa - dzielenie przez 0
        }

        // Eliminacja w kolejnych wierszach
        for (k = i + 1; k < mat->r; k++) {
            factor = mat->data[k][i] / mat->data[i][i];
            
            // Odejmowanie wielokrotności wiersza i od wiersza k
            for (j = i; j < mat->c; j++) {
                mat->data[k][j] -= factor * mat->data[i][j];
            }
            
            // Modyfikacja macierzy wyrazów wolnych
            b->data[k][0] -= factor * b->data[i][0];
        }
    }

    // Sprawdzenie czy ostatni element diagonalny jest bliski zeru
    if (fabs(mat->data[mat->r - 1][mat->r - 1]) < 1e-10) {
        return 1;  // Macierz osobliwa - dzielenie przez 0
    }

    return 0;  // Eliminacja zakończona sukcesem
}

