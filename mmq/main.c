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
    double l1[] = {3,-1,2},c[5];
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
    double x[] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2,2.1,2.2,2.3};
    double y[] = {13.75,14.51,14.49,13.98,12.69,11.05,8.83,5.66,4.68,7.79,10.11,12.33,13.64,14.32,
    14.53,13.83,12.08,10.60,8.13,5.6,4.72,6.45,9.08,12.09};
    printf("Teste MMQ\n\nNorma2 Residuo = %f\n",MMQ (5,3,A,b1,x1));
    exibeVetor(3,x1);
    printf("\nNorma2 Residuo = %f\n",MMQ (5,4,B,b2,x2));
    exibeVetor(4,x2);
    printf("\nTeste Periodico\n\nErro = %f\n",periodico(24,x,y,c));
    printf("Coeficientes: ");
    exibeVetor(5,c);
    printf("A extensao da area de gelo hoje(setembro/2019): %f\n",previsao(c,5.6));



    return 0;
}