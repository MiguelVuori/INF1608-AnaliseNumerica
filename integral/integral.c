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

    e_min = fabs(derivada(f,x,h_otimo) - fl(x));

    for (int i = 1; i < 12 ; i++)
    {
        h *= 0.1;
        e = fabs (derivada(f, x, h) - fl(x));
        if(e < e_min)
        {
            e_min = e;
            h_otimo = h;
            printf("h_otimo = %f \n",h_otimo);
        }
    }
    
    return h_otimo;
}