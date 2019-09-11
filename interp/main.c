#include <stdio.h>
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

    Chebyshev (6, 0, Pi/2 , xi);
    exibeVetor(6, xi);
    return 0;
}