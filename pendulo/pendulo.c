#include <stdio.h>
#include <math.h>
#include "pendulo.h"


double pendulo (double t,
                double h,
                double* theta, 
                double* w)
{
    double  k_theta[4], /* Vetor que armazena os coeficientes do angulo do pendulo */ 
            k_w[4];     /* Vetor que armazena os coeficientes da velocidade angular */
    int     i;

    k_theta[0] = h * (*w);
    k_w[0] = h * ((-g/l) * sin(*theta));

    for(i = 1 ; i < 3; i++)
    {
        k_theta[i] = h * (*w + (k_w[i - 1]/2));
        k_w[i] = h *  ((-g/l) * sin((*theta) + (k_theta[i - 1]/2)));

    }

    k_theta[i] = h * (*w + (k_w[i-1]));
    k_w[i] = h *  ((-g/l) * sin(*theta + k_theta[i-1]));

    (*w) = (*w) + (k_w[0] + 2*k_w[1] + 2*k_w[2] + k_w[3])/6;
    (*theta) = (*theta) + (k_theta[0] + 2*k_theta[1] + 2*k_theta[2] + k_theta[3])/6;


    return t + h ;

}


double periodo (double theta_0)
{
    double  w = 0.0,
            w1,
            t1,
            t = 0.0,
            theta = theta_0,
            T;

    int cont = 10;
    
    while(cont)
    {
        t1 = t;
        w1 = w;

        t = pendulo(t,H,&theta,&w);

        if(w1 * w < 0 || (w1 * w == 0))
            cont--;
 
    }

    T = 2 * (t1 + (fabs(w1)/(fabs(w1) + fabs(w))) * (t - t1));

    return T/10.0;


}

double periodo_simplificado (double theta0)
{
   return 2 * pi * sqrt(l/g);
}