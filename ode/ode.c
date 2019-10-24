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
            deltaY;

    
    for(t ; t < t1 ; t += h)
    {
        if(t + h > t1)
        {
            h = t1 - t;
        }

        deltaY = h * f(t,y);
        y = y + (h * f((t + (h/2)),y + (deltaY/2)));
    }

    return y;

}

double PontoMedioAdapt (double t0, 
                        double t1, 
                        double h0, 
                        double y0,
                        double (*f) (double t, double y), 
                        double tol)

{
    double  t = t0,
            t2,
            y = y0,
            y1,
            y2,
            h = h0,
            h2,
            e,
            gama,
            delta,
            deltaY;

    while (t < t1)
    {
        /* primeiro avanco */
        
        if(t + h > t1)
        {
            h = t1 - t;
        }
        deltaY = h * f(t,y);
        
        y1 = y + (h * f((t + (h/2)),y + (deltaY/2)));

        y2 = y;
        t2 = t;
        h2 = h/2.0;

        /* segundo avanco com h/2 */
        for(int i = 0; i < 2 ; i++)
        {
            deltaY  = h2 * f(t2,y2);
            y2 = y2 + (h2 * f((t2 + (h2/2)),y2 + (deltaY/2)));
            t2 += h2;
        }

        delta = y2 - y1;
        e = delta/3.0;

        gama = pow((tol/fabs(e)),(1.0/3.0));

        if (gama >= 1.0)
        {
            y = y2 + e;
            t += h;
        }

        h *= gama;

    }

    return y;

}