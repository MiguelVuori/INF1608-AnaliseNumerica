#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

double f1 (double x)
{
    return x*x + sin(x);
}

int main()
{
    double  tol = 0.0001,
            xmin;
    printf("O n de iteracoes(sacaoaurea) eh %d com min(f1) = ",secaoaurea (-10,10, f1, tol, &xmin));
    printf("%.12f\n", xmin);
    printf("O n de iteracoes(parabolica) eh %d com min(f1) = ",parabolica (-1.5,-1,0.5, f1, tol, &xmin));
    printf("%.12f\n", xmin);
    return 0;

}
