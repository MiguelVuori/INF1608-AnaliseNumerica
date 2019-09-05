#include "raiz.h"
#include <stdio.h>
#include <math.h>

double f (double x)
{
	return cos(x) - x*x*x + x;
}

int main (void)
{
	double r;
	int interacoes;
	
	interacoes = secante(0,-0.5,8,f,&r);
	printf("interacoes: %d\nraiz: %.17g\n",interacoes,r);
	
	interacoes = IQI(0, -0.5, 1, 6, f, &r);
	printf("\ninteracoes: %d\nraiz: %.17g\n",interacoes,r);
	
	return 0;
}
