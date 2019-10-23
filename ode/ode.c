#include <stdio.h>
#include <math.h>
#include "ode.h"

double PontoMedio (double t0,
                double t1,
                double h, 
                double y0, 
                double (*f) (double t, 
                double y))
{
    double  t = t0, 
            y = y0, 
            deltaY = f(t,y0);

    
    for(t ; t < t1 ; t += h)
    {
        if(t + h > t1)
            h = t1 - t;

        y = y + (h * f((t + (h/2)),y + (deltaY/2)));
    }

    return y;

}

double PontoMedioAdapt (double t0, 
                        double t1, 
                        double h0, 
                        double y0,
                        double (*f) (double t, double y), 
                        double tol);

{
    double  t = t0,
            y = y0,
            y1,
            y2,
            h = h0,
            e,
            gama,
            deltay = f(t,y0);

    while (t < t1)
    {
        y1 = y + (h * f((t + (h/2)),y + (deltaY/2)));

        for(int i = 0, i < 2 ; i++)
        {
            h2 = h/2
            y2 = y + (h2 * f((t + (h2/2)),y + (deltaY/2)));
        }

        deltaY = y2 - y1;
        e = deltaY/3;
        gama = pow((tol/fabs(e)),1/3)

        if (gama >= 1)
        {
            y = y2 + e
            h = gam
        }

    }

}