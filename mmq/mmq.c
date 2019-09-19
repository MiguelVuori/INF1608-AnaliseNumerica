#include <stdio.h>
#include "mmq.h"

double MMQ (int m, int n, double** A, double* b, double* x)
{
    double** T = matcria(n,m), **C = matcria(n,n);
    double* v = vetcria(m),*res = vetcria(m),* Atb = vetcria(m), norma;
    
    transposta (m,n,A,T);
    multmm (n,m,n,T,A,C);
    multmv (n,m,T,b,Atb);
    gauss (n,C,Atb,x);
    multmv (m,n,A,x,v);

    for(int i = 0; i < m; i++)
        res[i] = b[i] - v[i];

    norma = norma2(m,res);
    vetlibera(v);
    vetlibera(res);
    vetlibera(Atb);
    matlibera(n,T);
    matlibera(n,C);

    return norma;
}

double periodico (int n, double* t, double* v, double* c)
{
    double** A = matcria(n,5), res;
    int i,j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(j == 0)
                A[i][j] = 1;
            else if(j == 1)
                A[i][j] = t[i];
            else if(j == 2)
                A[i][j] = sin(2 * Pi * t[i]);
            else if (j == 3)
                A[i][j] = cos(2 * Pi * t[i]);
            else
                A[i][j] = cos(4 * Pi * t[i]); 
        }

    }

    res = MMQ(n,5,A,v,c);
    matlibera(n,A);
    return res;
}

double previsao (double* c, double t)
{

    return c[0] + c[1]*t + c[2]*sin(2*Pi*t) + c[3]*cos(2*Pi*t) + c[4]*cos(4*Pi*t);
}