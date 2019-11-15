#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

double f1 (double x)
{
    return x*x + sin(x);
}

double f2 (double x)
{
    return pow(x,6) - 11 * pow(x,3) + 17 * pow(x,2) - 7 * x + 1;
}

int main()
{
    double  tol = 0.0001,
            xmin;
    printf("O n de iteracoes(sacaoaurea) eh %d com min(f1) = ",secaoaurea (-10,10, f1, tol, &xmin));
    printf("%.12f\n", xmin);
    printf("O n de iteracoes(sacaoaurea) eh %d com min(f2) = ",secaoaurea (-10,10, f2, tol, &xmin));
    printf("%.12f\n", xmin);
    printf("O n de iteracoes(parabolica) eh %d com min(f1) = ",parabolica (-1.5,-1,0.5, f1, tol, &xmin));
    printf("%.12f\n", xmin);
    printf("O n de iteracoes(parabolica) eh %d com min(f2) = ",parabolica (-1.5,-1,0.5, f2, tol, &xmin));
    printf("%.12f\n", xmin);
    return 0;

}
