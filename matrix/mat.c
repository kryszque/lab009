#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mat.h"

matrix_t* zeros(unsigned int n, unsigned int m){
    double *v = calloc(n*m, sizeof(double));
    if(v == NULL){
        fprintf(stderr, "[!] Allocation for the data failed\n");
        return NULL;
    }
    matrix_t *A = malloc(sizeof(matrix_t));
    if(A == NULL){
        fprintf(stderr, "[!] Allocation for the matrix structure failed\n");
        return NULL;
    }
    A->n = n;
    A->m = m;
    A->v = v;
    printf("[] Allocated a %d x %d matrix\n", A->n, A->m);
    return A;
}

double getelm(matrix_t *A, unsigned int i, unsigned int j){
    if(A != NULL){
        if(i < A->n && j < A->m){
            return A->v[i*A->m + j];
        }else{
            fprintf(stderr, "[!] Accessing (%d,%d) in a %dx%d matrix \n", i, j, A->n, A->m);
        }
    }
    return NAN;
}

void destroy(matrix_t *A){
    if(A != NULL){
        if(A->v != NULL){
            free(A->v);
            A->v = NULL;
        }
    }
    free(A);
}


double* getrow(matrix_t* A, unsigned int i){
    if(A != NULL){
        if(i < A->n){ // assumes A-> is valid
            return (A->v + i*A->m); 

        }else{    
            fprintf(stderr, "[!] Accessing (%d,:) in a %d x %d matrix\n", i, A->n, A->m);
        }
    }
    return NULL;
}

void show(matrix_t *A){
    if(A != NULL){
        printf("%d x %d Matrix{double}\n", A->n, A->m);
        for(unsigned int i=0; i < A->n; i++){
            double *row = getrow(A, i);
            for(unsigned int j=0; j < A->m; j++){
                printf("%8.6g ", row[j]);
            }
            printf("\n");
        }
    }
}

unsigned int length(matrix_t *A){
    if(A != NULL){
        return (A->n * A->m);
    } 
    
    return 0;
}

void scalerow(matrix_t *A, unsigned int i, double alpha){
    if(A != NULL){
        double *row = getrow(A, i);
        if(row != NULL){
            for(unsigned int j=0; j < A->m; j++){
                row[j] *= alpha;
            }
        }
    }

}

void substractrow(matrix_t *A, unsigned int i1, unsigned int i2){
    if(A != NULL){
        double *r1 = getrow(A, i1);
        double *r2 = getrow(A, i2);

        if(r1 != NULL && r2 != NULL){
            for(unsigned int j=0; j < A->m; j++){
                r1[j] -= r2[j];
            }
        }
    }
}



