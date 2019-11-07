#include <stdio.h>
#include "metiter.h"
#include "matriz.h"

int Jacobi (int n, double** A, double* b, double* x, double tol)
{
    int interacoes = 0;
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
    vetlibera(res);
    return interacoes;
}

int GradConj (int n, double** A, double* b, double* x, double tol)
{
    int iteracoes,
        i;
    double  *res = vetcria(n),
            *res_post = vetcria(n),
            *d = vetcria(n),
            *Ad = vetcria(n),
            *alphaAd = vetcria(n),
            *alphaD = vetcria(n),
            *bethaD = vetcria(n),
            alpha,
            betha;

    multmv (n,n,A,x,res);

    for(i = 0 ; i < n ; i++)
    {
        res[i] = b[i] - res[i];
    }
    d = res;
    
    
    for(iteracoes = 0; iteracoes < n && norma2 (n,res) > tol; iteracoes++)
    {
        double res_escalar = escalar(n,res,res);

        multmv(n,n,A,d,Ad);

        alpha = (res_escalar/escalar(n,d,Ad));

        for(i = 0 ; i < n ; i++)
        {
            alphaAd[i] = alpha * Ad[i];
            res_post[i] = res[i] - alphaAd[i];

            alphaD[i] = alpha * d[i];
            x[i] = x[i] + alphaD[i];
        }

        betha = (escalar(n,res_post,res_post)/res_escalar);

        for(i = 0 ; i < n ; i++)
        {
            bethaD[i] = betha * d[i];
            d[i] = res_post[i] + bethaD[i]; 
        }

        res = res_post;

    }

    vetlibera(res);
    vetlibera(res_post);
    vetlibera(d);
    vetlibera(Ad);
    vetlibera(alphaAd);
    vetlibera(alphaD);
    vetlibera(bethaD);

    return iteracoes;
}