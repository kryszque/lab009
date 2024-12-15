#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b){
	int i;
	if(mat->data[mat->r-1][mat->c-1] == 0){
		return 1;
	}
	else{
		x->data[x->r-1][0] = mat->data[mat->r-1][mat->c-1];
	}

	for (i =0; i < x->r; i++) {
		x->data[i][0] = b->data[i][0];
	}

	return 0;
}


