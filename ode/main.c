#include <stdio.h>
#include "ode.h"

double f1(double t,double y)
{
    return (t*y) + (t*t*t);
}

int main(void)
{
    double  h = 0.01,
            y0 = -1,
            t0 = 0,
            t1 = 2.4;

    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,f1));
    h = 0.001;
    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,f1));
    h = 0.0001;
    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,f1));
    

    return 0;
}