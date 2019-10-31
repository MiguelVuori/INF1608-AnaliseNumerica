#include <stdio.h>
#include "pendulo.h"



int main ()
{
    double T,D2R = pi/180, thetas[] = {1*D2R,3*D2R,5*D2R,10*D2R,30*D2R,60*D2R,90*D2R};

    for(int i = 0 ; i < 7 ; i++)
    {

        T = periodo (thetas[i]);
        printf("periodo(theta = %f) = %.12f\n",(thetas[i]/D2R),T);
        T = periodo_simplificado (thetas[i]);
        printf("periodo_simplificado(theta = %f) = %.12f\n",(thetas[i]/D2R),T);
    }

    return 0;
}