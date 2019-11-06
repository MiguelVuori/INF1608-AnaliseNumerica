#include <stdio.h>
#include "metiter.h"
#include "matriz.h"

void eexibeVetor(int n, double* v)
{   
    int i;

    for(i = 0; i < n;i++)
    {
        printf("%f | ",v[i]);
    }
    printf("\n");
}

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

        multmv (n,n,LU,vet,x);
        eexibeVetor(n,x);

        vetlibera (vet);

        multmv (n,n,A,x,res);

        for(int i = 0 ; i < n ; i++)
        {
            res[i] = b[i] - res[i];
        }

        N2res = norma2 (n,res);

        interacoes++;
        printf("%f\n",N2res);

        if(interacoes == 10)
            break;
    }

    matlibera (n,LU);
    matlibera (n,DI);
    return interacoes;
}