#include "gauss.h"
#include "mat.h"

void eliminate(matrix_t *A){
    unsigned int rows = A->n;
    unsigned int cols = A->m;

    for(int i=0; i<cols; i++){
        for(int j=i+1; j<rows; j++){
            double licz = A->v[j*cols + i];
            double a_ii = A->v[i*cols + i];
            double alpha = licz/a_ii;
            scalerow(A, i, alpha);
            substractrow(A, j, i);
        }
    }

}
