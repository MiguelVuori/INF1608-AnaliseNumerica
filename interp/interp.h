#include <stdio.h>
#define Pi 3.141592653589793

/* Calcula as n amostras de chebyshev no intervalo entre a e b cujos valores sao armazenados em xi */
void Chebyshev (int n, double a, double b, double* xi);

/* Calcula os n coeficientes das diferenças de Newton a partir das abscissas de xi e a função a ser interpolada */ 
void NewtonCoef (int n, double* xi, double (*f) (double), double* bi);

/* Calcula a ordenada relacionada a abscissa x na função interpolante. Esse valor eh retornado */ 
double NewtonAval (int n, double* xi, double* bi, double x);

