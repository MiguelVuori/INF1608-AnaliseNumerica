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

double erroMaximoSin(int n, double a, double b)
{
    double fat = 1;
    for(int i = 2;i <= n; i++)
        fat *= i;

    return (pow((b - a)/2,n))/(pow(2,n-1)) * (1/fat);

}
int main (void)
{
    double xi[6];
    double bi[6];
    double f,g,h,i,j,k,l,m,erroMax;

    Chebyshev (6, 0, Pi/2 , xi);
    NewtonCoef (6, xi, sin, bi);
    printf("\nxi = ");
    exibeVetor(6, xi);
    printf("\nbi = ");
    exibeVetor(6, bi);
    f = NewtonAval (6, xi, bi, Pi/6);
    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/6),f);
    
    Chebyshev (6, -Pi/2, Pi/2 , xi);
    NewtonCoef (6, xi, sin, bi);
    f = NewtonAval (6, xi, bi, -Pi/2);
    g = NewtonAval (6, xi, bi, -Pi/3);
    h = NewtonAval (6, xi, bi, -Pi/4);
    i = NewtonAval (6, xi, bi, -Pi/6);
    j = NewtonAval (6, xi, bi, Pi/6);
    k = NewtonAval (6, xi, bi, Pi/4);
    l = NewtonAval (6, xi, bi, Pi/3);
    m = NewtonAval (6, xi, bi, Pi/2);

    erroMax = erroMaximoSin(6, -Pi/2, Pi/2);
    printf("\nErro maximo = %f\n", erroMax);

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(-Pi/2),f);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",-Pi/2,(fabs((sin(-Pi/2)-f)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(-Pi/3),g);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",-Pi/3,(fabs((sin(-Pi/3)-g)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(-Pi/4),h);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",-Pi/4,(fabs((sin(-Pi/4)-h)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(-Pi/6),i);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",-Pi/6,(fabs((sin(-Pi/6)-i)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/6),j);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",Pi/6,(fabs((sin(Pi/6)-j)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/4),k);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",Pi/4,(fabs((sin(Pi/4)-k)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/3),l);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",Pi/3,(fabs((sin(Pi/3)-l)) <= erroMax)?"sim":"nao");

    printf("\nValor real = %f\nValor pela interpolação = %f\n",sin(Pi/2),m);
    printf("Precisao requisitada foi atendida para x = %f?\nR: %s\n",Pi/2,(fabs((sin(Pi/2)-m)) <= erroMax)?"sim":"nao");

    return 0;
}