#include <stdio.h>
#include "metiter.h"
#include "matriz.h"

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
            x3[] = {0,0},
            tol = 1e-7,
            *M1[] = {v1,v2},
            u1[] = {3.,-1.,0.,0.,0.,0.5},
            u2[] = {-1.,3.,-1.,0.,0.5,0.},
            u3[] = {0.,-1.,3.,-1.,0.,0.},
            u4[] = {0.,0.,-1.,3.,-1.,0.},
            u5[] = {0.,0.5,0.,-1.,3.,-1.},
            u6[] = {0.5,0.,0.,0.,-1.,3.},
            *M2[] = {u1,u2,u3,u4,u5,u6},
            b2[] = {2.5,1.5,1,1,1.5,2.5},
            x2[] = {0,0,0,0,0,0},
            x4[] = {0,0,0,0,0,0};

    printf("Numero de interacoes(Jacobi) de M1 = %d\n",Jacobi (2,M1,b,x,tol));
    printf("Vetor Solucao:\n");
    exibeVetor(2,x);

    printf("Numero de interacoes(Jacobi) de M2 = %d\n",Jacobi (6,M2,b2,x2,tol));
    printf("Vetor Solucao:\n");
    exibeVetor(6,x2);

    printf("Numero de interacoes(GradConj) de M1 = %d\n",GradConj (2,M1,b,x3,tol));
    printf("Vetor Solucao:\n");
    exibeVetor(2,x3);

    printf("Numero de interacoes(GrandConj) de M2 = %d\n",GradConj (6,M2,b2,x4,tol));
    printf("Vetor Solucao:\n");
    exibeVetor(6,x4);
    return 0;
}