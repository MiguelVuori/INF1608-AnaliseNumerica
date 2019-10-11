#include <stdio.h>
#include "math.h"

double derivada (double (*f) (double x), double x, double h)
{
    return (f(x + h) - f(x - h))/(2 * h);
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x)
{
    /* x = 2.7 => hotimo = 10⁻5 */
    double h = 1, h_otimo = 0.1, e_min, e;

    if(f == NULL || fl == NULL)
        return 0;

    e_min = fabs(derivada(f,x,h_otimo) - fl(x));

    for (int i = 1; i < 12 ; i++)
    {
        h *= 0.1;
        e = fabs (derivada(f, x, h) - fl(x));
        if(e < e_min)
        {
            e_min = e;
            h_otimo = h;
        }
    }
    
    return h_otimo;
}

double richardson (double (*f) (double x), double x, double h)
{

    return ((pow(2,3) * derivada(f,x,h/2)) - derivada(f,x,h))/(pow(2,3) - 1);
}

double simpson (double (*f) (double), double a, double b, int n)
{
    double h = (b-a)/n,soma = 0,fesq,fdir = f(a);

    for (int i = 0; i < n ; i++)
    {
        fesq = fdir;
        fdir = f(a + h * (i + 1));
        soma += (h/6) * (fesq + 4 * f(a + h * i + (h/2)) + fdir);
    }
    return soma;
}

double pontomedio (double (*f) (double), double a, double b, int n)
{
    double h = (b - a)/n,soma = 0, pmedio,xesq,xdir;

    xdir = a;

    for (int i = 0; i < n; i++)
    {
        xesq = xdir;
        xdir = a + h * (i + 1);
        pmedio = (xesq + xdir)/2 ;

        soma += h * f(pmedio);
    }
    
    return soma;

}



