#ifndef __MAT_H__
#define __MAT_H__

typedef struct {
    unsigned int n;
    unsigned int m;
    double *v;
} matrix_t;

matrix_t* zeros(unsigned int n, unsigned int m);
void scalerow(matrix_t *A, unsigned int i, double alpha);
void destroy(matrix_t *A);
double* getrow(matrix_t *A, unsigned int i);
double getelm(matrix_t *A, unsigned int i, unsigned int j);
void show(matrix_t *A);
void substractrow(matrix_t *A, unsigned int r1, unsigned int r2);
unsigned int length(matrix_t *A);

#endif
