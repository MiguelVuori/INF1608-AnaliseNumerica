#include <stdio.h>
#include <math.h>
#include "ode.h"

double derivadaf1(double t,double y)
{
    return (t*y) + (t*t*t);
}

double f1(double t)
{
    return exp(t*t/2) - (t*t) - 2;
}
int main(void)
{
    double  h = 0.01,
            y0 = -1,
            t0 = 0,
            t1 = 2.4,
            exato = f1(2.4),
            aproximacao,
            tol = 0.0001;

    aproximacao = PontoMedio (t0,t1,h,y0,derivadaf1);
    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,derivadaf1));
    printf("Erro relativo = %.12f\n",fabs((exato - aproximacao)/aproximacao));
    aproximacao = PontoMedio (t0,t1,h,y0,derivadaf1);
    h = 0.001;
    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,derivadaf1));
    printf("Erro relativo = %.12f\n",fabs((exato - aproximacao)/aproximacao));
    aproximacao = PontoMedio (t0,t1,h,y0,derivadaf1);
    h = 0.0001;
    printf("Ponto Medio(h = %f) = %.12f\n",h,PontoMedio (t0,t1,h,y0,derivadaf1));
    printf("Erro relativo = %.12f\n",fabs((exato - aproximacao)/aproximacao));

    aproximacao = PontoMedioAdapt (t0,t1,h,y0,derivadaf1,tol);
    printf("Ponto Medio Adapativo(h e tolerancia = %f) = %.12f\n",h,aproximacao);
    printf("Erro relativo = %.12f\n",fabs((exato - aproximacao)/aproximacao));

    

    return 0;
}