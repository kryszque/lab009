#include <stdio.h>
#include "mat.h"
#include "gauss.h"
int main(int argc, char** argv){
    matrix_t *A = zeros(3, 4);
    
    for(unsigned int k=0; k < length(A); k++){
        A->v[k] = (double) k;
    }
    printf("[] A[%d, %d] = %g\n", 2, 2, getelm(A, 2, 2));

    scalerow(A, 0, 0.2);
    show(A);
    substractrow(A, 0, 1);
    eliminate(A);
    show(A);
    destroy(A);

    return 0;
}
