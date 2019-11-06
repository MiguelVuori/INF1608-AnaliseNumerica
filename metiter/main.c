#include <stdio.h>
#include "metiter.h"

void exibeVetor(int n, double* v)
{   
    int i;

    for(i = 0; i < n;i++)
    {
        printf("%f | ",v[i]);
    }
    printf("\n");
}

int main ()
{
    double  v1[] = {3.,1.},
            v2[] = {1.,2.},
            b[] = {5,5},
            x[] = {0,0},
            tol = 1e-7,
            *M1[] = {v1,v2};

    printf("Numero de interacoes = %d\n",Jacobi (2,M1,b,x,tol));
    printf("Vetor Solucao:\n");
    exibeVetor(2,x);
    return 0;
}