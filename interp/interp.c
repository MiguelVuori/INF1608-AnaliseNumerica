#include <stdio.h>
#include <math.h>
#include "interp.h"
#include "matriz.h"

/* Protótitpo das funções encapsuladas */

double DDNewton (int n, double *xi, double (*f) (double), int i, int j);

void Chebyshev (int n, double a, double b, double* xi)
{
    for(int i = 1; i < n; i++)
    {
        int beta = 2 * i - 1;
        xi[i - 1] = ((b - a)/2) * cos((beta * Pi)/(2*n)) + ((a + b)/2) ;
    }

}

void NewtonCoef (int n, double* xi, double (*f) (double), double* bi)
{
    double** mat = matcria (n,n);
    int i, j;
    for(j = 0; j < n; j++)
    {
        for(i = j; i >= 0; i--)
        {
            if(i == j)
            {
                mat[i][j] = f(xi[i]);
            }
            else
            {
                mat[i][j] = (mat[i+1][j] - mat[i][j-1]) / (xi[j] - xi[i]);
            }
        }
        bi[j] = mat[0][j];
    }
    matlibera ( n, mat);

}

/*
void NewtonCoef (int n, double* xi, double (*f) (double), double* bi)
{

    for (int i = 0; i < n; i++)
        bi[i] = DDNewton(n, xi, f, 0, i);  // IMPLEMENTAÇÃO SEM CACHE
}
*/


double NewtonAval (int n, double* xi, double* bi, double x)
{
    double aux[n];  //armazena valores acumulados do produtorio de (x - xi) 
    double f;  //avaliação 

    for(int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            aux[i] = 1;
            f = bi[i];
        }
        else
        {
            aux[i] = aux[i-1] * (x - xi[i-1]);
            f = f + (bi[i] * aux[i]);
        }
    }

    return f;

}

/* Funções encapsuladas */

double DDNewton (int n, double *xi, double (*f) (double), int i, int j)
{
    if(i == j)
        return f(xi[i]);
    else
        return (DDNewton(n, xi, f, i+1, j) - DDNewton(n, xi, f, i,j - 1)) / (xi[j] - xi[i]); 

}
