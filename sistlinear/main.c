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

    gauss(3, A, b, x);
    exibeVetor(3, x);
    printf("\n");
    matexibe (3, 3, A);

    gauss(6, B, c, y);
    printf("\n");
    exibeVetor (6, y);
    printf("\n");
    matexibe (6, 6, B);

    return 0;
}