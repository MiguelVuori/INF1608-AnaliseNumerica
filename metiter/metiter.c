#include <stdio.h>
#include "metiter.h"
#include "matriz.h"

int Jacobi (int n, double** A, double* b, double* x, double tol)
{
    int interacoes = 0, tam = n;
    double **LU, **DI, N2res, *res;//res = b -  Ax

    LU = matcria (n,n);
    res = vetcria (n);
    DI = matcria (n,n);

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
            if (j != i)
            {
                LU[i][j] = A[i][j];
                DI[i][j] = 0;
            }
            else
            {
               DI[i][j] = 1/A[i][j];
               LU[i][j] = 0; 
            }
    }

    multmv (n,n,A,x,res);

    for(int i = 0 ; i < n ; i++)
    {
        res[i] = b[i] - res[i];
    }
    
    N2res = norma2 (n,res);

    while(N2res > tol)
    {
        double *vet = vetcria (n);;
            
            
        multmv (n,n,LU,x,vet);
        
        
        for (int j = 0; j < n ; j++)
        {
            vet[j] = b[j] - vet[j];
        }

        multmv (n,n,DI,vet,x);

        vetlibera (vet);

        multmv (n,n,A,x,res);

        for(int i = 0 ; i < n ; i++)
        {
            res[i] = b[i] - res[i];
        }

        N2res = norma2 (n,res);

        interacoes++;
    }

    matlibera (n,LU);
    matlibera (n,DI);
    return interacoes;
}

int GradConj (int n, double** A, double* b, double* x, double tol)
{
    int iteracoes = 0, tam = n;
    double *res = vetcria(n), *d = vetcria(n),N2res,alpha,
    *Ad = vetcria(n),alphaD[n],*res_post = vetcria(n),betha;

    multmv (n,n,A,x,res);

    for(int i = 0 ; i < n ; i++)
    {
        res[i] = b[i] - res[i];
    }
    d = res;
    
    N2res = norma2 (n,res);

    while(N2res > tol)
    {
        multmv(n,n,A,d,Ad);
        alpha = escalar(n,res,res)/escalar(n,d,Ad);

        for(int i = 0 ; i < n ; i++)
        {
            Ad[i] = alpha * Ad[i];
            alphaD[i] = alpha * d[i];
            res_post[i] = res[i] - Ad[i];
            x[i] = x[i] + alphaD[i]; 
        }

        betha = escalar(n,res_post,res_post)/escalar(n,res,res);

        for(int i = 0 ; i < n ; i++)
        {
            alphaD[i] = betha * d[i];
            d[i] = res_post[i] + alphaD[i]; 
        }

        for(int i = 0 ; i < n ; i++)
        {
            res_post[i] = b[i] - res_post[i];
        }

        res = res_post;
        N2res = norma2 (n,res);

    iteracoes++;
    } 
}