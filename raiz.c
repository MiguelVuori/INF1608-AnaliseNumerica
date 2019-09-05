#include <stdio.h>
#include <math.h>

int secante (double x0, double x1, int p, double (*f) (double x), double* r)
{
	double ps = 0.5 * pow(10,-p);
	double y0 = (*f)(x0);
	double y1 = (*f)(x1);
	double x2 = x1 - (y1 * (x1 - x0))/(y1 - y0);
	double y2 = (*f)(x2);
	double e = fabs(y2);
	int interacoes = 1;
	
	while(e >= ps)
	{
		if (interacoes == 50)
			return 0;
		y0 = y1;
		y1 = y2;
		x0 = x1;
		x1 = x2;
		x2 = x1 - (y1 * (x1 - x0))/(y1 - y0);
		y2 = (*f)(x2);
		e = fabs(y2);
		interacoes++;
	}
	*r = x2;
	
	return interacoes;
	
	/*if (e < ps)
	secante (x1,x2,p,(*f)(),r)*/
	
	
}


int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r)
{
	double y0 = (*f)(x0);
	double y1 = (*f)(x1);
	double y2 = (*f)(x2);
	double ps = 0.5 * pow(10,-p);
	double c = ((x0*(y1*y2))/(y0*y0 -y2*y0 -y1*y0 + y1*y2)) + ((x1*(y0*y2))/(y1*y1 -y2*y1 -y1*y0 + y0*y2)) + ((x2*(y0*y1))/(y2*y2 -y2*y1 -y2*y0 + y1*y0));
	double y3 = (*f)(c);
	int interacoes = 1;
	double e = fabs(c);
	
	while(e >= ps)
	{
		if (interacoes == 50)
			return 0;
			
		y0 = y1;
		y1 = y2;
		y2 = y3;
		x0 = x1;
		x1 = x2;
		x2 = c;
		
		c = ((x0*(y1*y2))/(y0*y0 -y2*y0 -y1*y0 + y1*y2)) + ((x1*(y0*y2))/(y1*y1 -y2*y1 -y1*y0 + y0*y2)) + ((x2*(y0*y1))/(y2*y2 -y2*y1 -y2*y0 + y1*y0));
		y3 = (*f)(c);
		e = fabs(y3);
		printf("\n\nc: %.17g\n",c);
		interacoes++;
	}
	*r = c;
	
	return interacoes;
}
