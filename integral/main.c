#include <stdio.h>
#include "math.h"
#include "integral.h"

double dervAnal(double x)
{
    return -sin(x) - (2 * cos(x));
}

double f(double x)
{
    return cos(x) - (2 * sin(x));
}

int main ()
{
    printf("h_otimo = %f\n",h_otimo(f,dervAnal,2.7));

    return 0;
}