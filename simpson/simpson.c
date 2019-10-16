#include <stdio.h>
#include <math.h>
#include "simpson.h"

double DoubleSimpson (double a, double b, double (*f) (double x), double* v)
{
    double c = (a + b)/2, h = c - a, S2,S1,S0;
    
    S1 = (h/6)*(f(a) + 4*f((a+c)/2) + f(c));
    S2 = (h/6)*(f(c) + 4*f((c+b)/2) + f(b));
    S0 = ((b-a)/6)*(f(a) + 4*f((a+b)/2) + f(b));

    *v = S1 + S2 - (fabs(S0 - S1 - S2))/15;

    return (fabs(S0 - S1 - S2))/15;
}

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol)
{
    double v, erro = DoubleSimpson (a,b,f,&v);
    if (erro < tol)
        return v;

    return AdaptiveSimpson (a,(a+b)/2, f, tol/2) + AdaptiveSimpson ((a+b)/2, b, f, tol/2);
}