#include <stdio.h>
#include <math.h>
#include "interp.h"


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
    double xi[6];
    double bi[6];
    double f;

    Chebyshev (6, 0, Pi/2 , xi);
    NewtonCoef (6, xi, sin, bi);
    exibeVetor(6, xi);
    exibeVetor(6, bi);
    f = NewtonAval (6, xi, bi, Pi/6);
    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/6),f);
    return 0;
}