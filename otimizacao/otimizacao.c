#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

int secaoaurea (double a, 
                double b, 
                double (*f) (double x),
                double tol, 
                double* xmin)
{
    double  g = (sqrt(5) - 1)/2,
            x1 = a + ((1 - g) * (b - a)),
            x2 = a + (g * (b - a)),
            f1 = f(x1),
            f2 = f(x2);
    int     cont = 0;

    while(fabs(f1 - f2) > tol)
    {

        if(f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + ((1 - g) * (b - a));
            f1 = f(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (g * (b - a));
            f2 = f(x2);
        }

        cont++;

    }

    *xmin = (x1 + x2)/2;
    
    return cont;

}

int parabolica (double r,
                double s, 
                double t, 
                double (*f) (double x),
                double tol, 
                double* xmin)
{
    double  fs = f(s),
            fr = f(r),
            ft = f(t),
            x = ((r + s) / 2) - ((fs - fr)*(t - r)*(t - s))/(2 * ((s-r)*(ft - fs) - (fs - fr)*(t - s)));
    int     cont;

    while(fabs(fs - ft) > tol)
    {
        x = ((r + s) / 2) - ((fs - fr)*(t - r)*(t - s))/(2 * ((s-r)*(ft - fs) - (fs - fr)*(t - s)));
        r = s;
        fr = fs;
        s = t;
        fs = ft;
        t = x;
        ft = f(t);
        cont++;

        if (cont == 100)
            return 0;
    }

    *xmin = (s + t)/2;
    //*xmin = x;

    return cont;

}