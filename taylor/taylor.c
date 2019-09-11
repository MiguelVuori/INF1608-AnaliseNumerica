#include <stdio.h>
#define pi 3.14159
double cos2 (double x)
{
	return 1 - (x*x);
}

double cos2_rmax (double x)
{	double residuo = (4 * x * x * x)/6;
	if (residuo<0)
		return -residuo;
	else
		return residuo;
}

double raiz (double x)
{
	return (1 + (x-1)/2 - ((1/4)*(x*x - 2*x + 1)/2) + ((3/8)* (x*x*x - 3*x*x + 3*x -1)/6));  
}

double raiz_rmax (double x)
{
	double residuo =- 0.03906 + 0.1562*x - 0.2343*x*x + 0.1562*x*x*x -0.03906*x*x*x*x;
	if (residuo < 0)
		return -residuo;
	else
		return residuo;
}