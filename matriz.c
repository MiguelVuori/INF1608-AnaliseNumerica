#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double* vetcria (int n) {

    double *ptr;
    ptr = (double *)malloc(sizeof(double) * n);
    return ptr;

}


void vetlibera (double* v) {

    free(v);

}


double escalar (int n, double* v, double* w) {

    double res = 0;
    for(int i = 0; i < n; i++) {
        res = res + v[i] * w[i];
    }
    return res;

}


double norma2 (int n, double* v) {

    double res = 0;
    for(int i = 0; i < n; i++) {
        res = res + v[i] * v[i];
    }
    res = sqrt(res);
    return res;

}


double** matcria (int m, int n) {

    double** ptr;
    ptr = (double **)malloc(sizeof(double *) * m);
    for(int i = 0; i < m; i++) {
        ptr[i] = vetcria(n);
    }
    return ptr;
}


void matlibera (int m, double** A) {

    for(int i = 0; i < m; i++) {
        vetlibera(A[i]);
    }
    free(A);

}


void transposta (int m, int n, double** A, double** T) {

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            T[i][j] = A[j][i];
        }
    }

}


void multmv (int m, int n, double** A, double* v, double* w) {

    for(int j = 0; j < m; j++) {
        w[j] = 0;
        for(int i = 0; i < n; i++) {
            w[j] = w[j] + A[j][i] * v[i];
        }
    }

}


void multmm (int m, int n, int q, double** A, double** B, double** C) {

    double** B_transposta = matcria(q, n);
    transposta(n, q, B, B_transposta);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            C[i][j] = escalar(n, A[i], B_transposta[j]);
        }
    }

}

void matexibe (int m, int n,double** A)
{   
    int i,j;

    for(i = 0; i <= m -1; i++)
    {
        for(j = 0; j <= n - 1; j++)
        {
            printf("%f | ",A[i][j]);
        }
        printf("\n");
    } 
}