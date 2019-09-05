#include "taylor.h"
#include <stdio.h>
#include <math.h>
#define pi 3.14159

int main(void)
{
	double f1 = cos2(pi);
	double f2 = cos(pi)*cos(pi);
	double f3 = raiz(0.5);
	double f4 = sqrt(0.5);
	double erro1 = fabs(f2 - f1);
	double res1 = cos2_rmax(pi);
	double erro2 = fabs(f4 - f3);
	double res2 = raiz_rmax(3);
	printf("Utilizando a funcao cos2(pi): %f\nUtilizando math.h: %f\n",f1,f2);
	printf("erro(%f) eh menor do que o residuo maximo(%f)?\n\n",erro1,res1);
	printf("Utilizando a funcao raiz(0.5): %f\nUtilizando math.h: %f\n",f3,f4);
	printf("erro(%f) eh menor do que o residuo maximo(%f)?\n",erro2,res2);
	return 0;
}