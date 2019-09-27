#include <stdio.h>
#include "qr.h"
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
    double** Q = matcria(5, 3),**Q2 = matcria(5, 4);
    double** R = matcria(3, 3),**R2 = matcria(4, 4);
    double** res = matcria(5, 3),** res2 = matcria(5, 4);
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
    double x1[3], x2[5];
    double erro;
    double b1[] = {10,10,-5,15,0},b2[] = {10,0,2,0,5};

    QR(5, 3, A, Q, R);
    matexibe(5, 3, Q);
    printf("\n--------------------------------\n");
    matexibe(3, 3, R);
    printf("\n--------------------------------\n");
    multmm(5, 3, 3, Q, R, res);
    matexibe(5, 3, res);

    printf("\n\n\n");

    QR(5, 4, B, Q2, R2);
    matexibe(5, 4, Q2);
    printf("\n--------------------------------\n");
    matexibe(4, 4, R2);
    printf("\n--------------------------------\n");
    multmm(5, 4, 4, Q2, R2, res2);
    matexibe(5, 4, res2);


    printf("\n\nTestando matriz 1\n\n");
    erro = mmqQR (5,3,Q,R,b1,x1);
    exibeVetor(3,x1);

    printf("\n\nTestando matriz 2\n\n");
    erro = mmqQR (5,4,Q2,R2,b2,x2);
    exibeVetor(4,x2);

    matlibera(5,Q);
    matlibera(5,Q2);
    matlibera(3,R);
    matlibera(4,R2);
    matlibera(5,res);
    matlibera(5,res2);

    return 0;
}