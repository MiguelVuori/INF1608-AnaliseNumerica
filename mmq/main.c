#include <stdio.h>
#include "mmq.h"

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
    double l1[] = {3,-1,2};
    double l2[] = {4,1,0};
    double l3[] = {-3,2,1};
    double l4[] = {1,1,5};
    double l5[] = {-2,0,3};
    double* A[] = {l1,l2,l3,l4,l5};
    double l6[] = {4,2,3,0};
    double l7[] = {-2,3,-1,1};
    double l8[] = {1,3,-4,2};
    double l9[] = {1,0,1,-1};
    double l10[] = {3,1,3,-2};
    double* B[] = {l6,l7,l8,l9,l10};
    double x1[3];
    double x2[5];
    double b1[] = {10,10,-5,15,0};
    double b2[] = {10,0,2,0,5};

    printf("\nResiduo = %f\n",MMQ (5,3,A,b1,x1));
    exibeVetor(3,x1);

    return 0;
}