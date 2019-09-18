#include <stdio.h>
#include "mmq.h"

double MMQ (int m, int n, double** A, double* b, double* x)
{
    double** T = matcria(n,m), **C = matcria(n,n);
    double* v = vetcria(m),*res = vetcria(m),* Atb = vetcria(m);
    transposta (m,n,A,T);
    multmm (n,m,n,T,A,C);
    multmv (n,m,T,b,Atb);
    gauss (n,C,Atb,x);

    multmv (m,n,A,x,v);

    for(int i = 0; i < m; i++)
        res[i] = b[i] - v[i];


    return norma2 (m,res);
}

double periodico (int n, double* t, double* v, double* c)
{

    return 0;
}

double previsao (double* c, double t)
{

    return 0;
}