#include <stdio.h>
#include <math.h>
#include "simpson.h" 

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
    printf("Erro simpson = %.12f\n",DoubleSimpson(0,1,f2,&v));
    printf("Valor da integral = %.12f\n\n",v);

    printf("Teste f3\n");
    printf("Erro simpson = %.12f\n",DoubleSimpson(0,1,f3,&v));
    printf("Valor da integral = %.12f\n\n",v);

    printf("Teste Simpson adaptativo\n");
    printf("Teste f1\n");
    printf("Erro simpson adaptativo = %.12f\n",AdaptiveSimpson(0,1,f1,0.0000016));
    //printf("Valor da integral = %.12f\n\n",v);

    printf("Teste f2\n");
    printf("Erro simpson adaptativo = %.12f\n",AdaptiveSimpson(0,1,f2,0.000029));
    //printf("Valor da integral = %.12f\n\n",v);

    printf("Teste f3\n");
    printf("Erro simpson adaptativo = %.12f\n",AdaptiveSimpson(0,1,f3,0.000021));
    //printf("Valor da integral = %.12f\n\n",v);



    return 0;
}