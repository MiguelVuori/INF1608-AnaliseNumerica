#include <stdio.h>
#include "math.h"
#include "integral.h"
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286
double dervAnal(double x)
{
    return -sin(x) - (2 * cos(x));
}

double f(double x)
{
    return cos(x) - (2 * sin(x));
}

double f1(double x)
{
    return (x/(sqrt(pow(x,2) + 9)));
}

double f2(double x)
{
    return x * x * log(x);
}

double f3(double x)
{
    return x * x * sin(x);
}


int main ()
{
    printf(" Teste das derivadas\n\n");

    printf("h_otimo  avaliado pelo metodo= %.12f\n",h_otimo(f,dervAnal,2.7));
    printf("h_otimo  teorico = 0.00001\n");
    printf("derivada usando h qualquer= %.12f\n",derivada(f,2.7,0.1));
    printf("derivada usando hOtimo= %.12f\n",derivada(f,2.7,0.00001));
    printf("derivada analitica= %.12f\n",dervAnal(2.7));

    printf("\n\n");

    printf("metodo Richardson= %.12f\n",richardson(f,2.7,0.00001));
    printf("metodo numerico= %.12f\n",derivada(f,2.7,0.00001));
    printf("derivada analitica= %.12f\n",dervAnal(2.7));
    printf("erro1 (richardson)= %.12f\n",fabs(dervAnal(2.7) - richardson(f,2.7,0.00001)));
    printf("erro2 (derivada numerica)= %.12f\n",fabs(dervAnal(2.7) - derivada(f,2.7,0.00001)));

    printf("\n\n Teste das integrais \n\n");

    printf("integral por simpson para f1 com 16 passos = %.15f \n", simpson(f1,0,4,16));
    printf("integral por simpson para f1 com 32 passos = %.15f \n", simpson(f1,0,4,32));
    printf("integral por simpson para f2 com 16 passos = %.15f \n", simpson(f2,1,3,16));
    printf("integral por simpson para f2 com 32 passos = %.15f \n", simpson(f2,1,3,32));
    printf("integral por simpson para f3 com 16 passos = %.15f \n", simpson(f3,0,pi,16));
    printf("integral por simpson para f3 com 32 passos = %.15f \n", simpson(f3,0,pi,32));

    printf("integral por ponto medio para f1 com 16 passos = %.15f \n", pontomedio(f1,0,4,16));
    printf("integral por ponto medio para f1 com 32 passos = %.15f \n", pontomedio(f1,0,4,32));
    printf("integral por ponto medio para f2 com 16 passos = %.15f \n", pontomedio(f2,1,3,16));
    printf("integral por ponto medio para f2 com 32 passos = %.15f \n", pontomedio(f2,1,3,32));
    printf("integral por ponto medio para f3 com 16 passos = %.15f \n", pontomedio(f3,0,pi,16));
    printf("integral por ponto medio para f3 com 32 passos = %.15f \n", pontomedio(f3,0,pi,32));

    printf("O metodo simpson apresenta melhor precisao e o aumento do numero de passos aumenta a precisao");

    return 0;
}