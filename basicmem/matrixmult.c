#include <stdio.h>
#include <stdlib.h>

float **create_matrix(int rows, int columns) {
    float **m;
    int i;

    m = (float **) malloc(sizeof(float *) * rows);

    for (i = 0; i < columns; ++i) {
        m[i] = (float *) malloc(sizeof(float) * columns);
    }

    return m;
}

void free_matrix(float **mat, int rows, int columns)

{
    int i;

    for (i = 0; i < columns; ++i) {
        free(mat[i]);
    }
    free(mat);


}

float **matrixmult(float **a, int ar, int ac, float **b, int br, int bc)
{
    int i,j,k;
    float **res;
    int sum;

    res = create_matrix(ar, bc);

    for (i = 0; i < ar; ++i) {
        for (j = 0; j < bc; ++j) {
            sum = 0;
            for (k = 0; k < ac; ++k) {
                sum += a[i][k] + b[k][j];
            }
            res[i][j] = sum;
        }
    }

    return res;
}

void randmat(float **a, int r, int c) {
    int i,j;

    srand(time(NULL));

    for (i=0; i < r; ++i) {
        for (j=0; j < c; ++j) {
            a[i][j] = rand() % 1000;
        }
    }
}

int iszero(float **a, int r, int c) {
    int i,j;

    for (i=0; i < r; ++i) {
        for (j=0; j < c; ++j) {
            if (a[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_matrix(float **a, int r, int c) {
    int i, j;

    for (i=0; i < r; ++i) {
        for (j=0; j < c ; ++j) {
            printf("%lf",a[i][j]);
            if (j < c - 1) {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int main() {
    float **a;
    float **b;
    float **res;

    a = create_matrix(2, 2);
    randmat(a, 2, 2);

    b = create_matrix(2, 2);
    b[0][0] = 1;
    b[1][1] = 1;

    res = matrixmult(a,2,2,b,2,2);

    print_matrix(res, 2, 2);

    return -1;
}
