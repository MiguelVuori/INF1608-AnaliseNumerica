#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sistlinear.h"
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

int main (void)
{
    double l1[] = {1,-1,0};
    double l2[] = {-1,2,1};
    double l3[] = {0,1,2};
    double l4[] = {3,-1,0,0,0,0.5};
    double l5[] = {-1,3,-1,0,0.5,0};
    double l6[] = {0,-1,3,-1,0,0};
    double l7[] = {0,0,-1,3,-1,0};
    double l8[] = {0,0.5,0,-1,3,-1};
    double l9[] = {0.5,0,0,0,-1,3};
    double* A[] = {l1,l2,l3};
    double x[] = {0,0,0};
    double b[] = {0,2,3};
    double* B[] = {l4,l5,l6,l7,l8,l9};
    double y[] = {0,0,0,0,0,0};
    double c[] = {2.5,1.5,1,1,1.5,2.5};

	/* teste da eliminacao de gauss */
	printf("Matriz antes da eliminacao de gauss de uma matriz 3x3:\n");
	matexibe (3, 3, A);
    gauss(3, A, b, x);
	printf("\nVetor solucao da matriz 3x3:\n");
    exibeVetor(3, x);
    printf("\n");
	printf("Matriz depois da eliminacao de gauss:\n");
    matexibe (3, 3, A);

	printf("\nMatriz antes da eliminacao de gauss de uma matriz 6x6:\n");
	matexibe (6, 6, B);
    gauss(6, B, c, y);
    printf("\nVetor solucao da matriz 6x6:\n");
    exibeVetor (6, y);
    printf("\n");
	printf("Matriz depois da eliminacao de gauss:\n");
    matexibe (6, 6, B);


	/* teste fatoracao de cholesky */
	double m1[] = {3,-1,0,0,0,0.5};
    double m2[] = {-1,3,-1,0,0.5,0};
    double m3[] = {0,-1,3,-1,0,0};
    double m4[] = {0,0,-1,3,-1,0};
    double m5[] = {0,0.5,0,-1,3,-1};
    double m6[] = {0.5,0,0,0,-1,3};
	double* C[] = {m1,m2,m3,m4,m5,m6};
	
	printf("\nMatriz 6x6 antes da fatoracao de cholesky:\n");
	matexibe (6, 6, C);
	cholesky(6,C);
	printf("\nMatriz 6x6 depois da fatoracao de cholesky:\n");
	matexibe (6, 6, C);

	/* teste da substituicao */
	double k[] = {0,0,0,0,0,0};
	double d[] = {2.5,1.5,1,1,1.5,2.5};
	printf("\nMatriz 6x6 fatorada antes das substituicoes:\n");
	matexibe (6, 6, C);
	substituicoes (6, C, d, k);
	printf("\nVetor solucao depois das substituicoes:\n");
	exibeVetor(6, k);

    return 0;
}