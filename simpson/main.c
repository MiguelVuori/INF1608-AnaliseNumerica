#include <stdio.h>
#include <math.h>
#include "simpson.h"
#define Pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286

double f1(double x)
{
    return x/(sqrt(x * x + 9));
}

double f2(double x)
{
    return exp((-(x*x))/2);
}

double f3(double x)
{
    return exp(-(x*x));
}

int main ()
{
    double v;

    printf("Teste f1\n");
    printf("Erro simpson = %.12f\n",DoubleSimpson(0,1,f1,&v));
    printf("Valor da integral = %.12f\n\n",v);

    printf("Teste f2\n");
    printf("Erro simpson = %.12f\n",DoubleSimpson(-1,1,f2,&v));
    printf("Valor da integral = %.12f\n\n",(1/(sqrt(2 * Pi))) * v);

    printf("Teste f3\n");
    printf("Erro simpson = %.12f\n",DoubleSimpson(0,3,f3,&v));
    printf("Valor da integral = %.12f\n\n",(2/sqrt(Pi))* v);

    printf("Teste Simpson adaptativo\n");
    printf("Teste f1\n");
    printf("Simpson adaptativo = %.12f\n",AdaptiveSimpson(0,1,f1,0.0000016));

    printf("\nTeste Quadratura de Gauss adaptativo\n");
    printf("Quadratura2 de f1= %.12f\n",Quadratura2 ( 0, 1, f1 ));
    printf("Quadratura3 de f1= %.12f\n",Quadratura3 ( 0, 1, f1 ));


    return 0;
}