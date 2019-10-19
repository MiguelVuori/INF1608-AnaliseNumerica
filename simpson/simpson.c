#include <stdio.h>
#include <math.h>
#include "simpson.h"


/* Protótipo das funções encapsuladas pelo módulo */

static double TransformaQuadratura( double a, double b, double t, double (*f) (double x) );

/* Funções exportadas pelo módulo */

double DoubleSimpson (double a, double b, double (*f) (double x), double* v)
{
    double c = (a + b)/2, h = c - a, S2,S1,S0;
    
    S1 = (h/6)*(f(a) + 4*f((a+c)/2) + f(c));
    S2 = (h/6)*(f(c) + 4*f((c+b)/2) + f(b));
    S0 = ((b-a)/6)*(f(a) + 4*f((a+b)/2) + f(b));

    *v = S1 + S2 - (fabs(S0 - S1 - S2))/15;

    return (fabs(S0 - S1 - S2))/15;
}

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol)
{
    double v, erro = DoubleSimpson (a,b,f,&v);
    if (erro < tol)
        return v;

    return AdaptiveSimpson (a,(a+b)/2, f, tol/2) + AdaptiveSimpson ((a+b)/2, b, f, tol/2);
}

double Quadratura2 ( double a , double b , double (*f) (double x) )
{
   double x[2] = { - sqrt((double)1/3) , 
                     sqrt((double)1/3) };

   double c[2] = { 1 , 1 };
   double soma = 0;

   int i;

   for( i = 0 ; i < 2 ; i++ )
      soma += c[i]*TransformaQuadratura(a,b,x[i],f);

   return soma;
}

/*
------------------------------------------
QUADRATURA COM 3 AMOSTRAS
------------------------------------------
*/

double Quadratura3 ( double a , double b , double (*f) (double x) )
{
   double x[3] = { - sqrt((double)3/5) , 0 , sqrt((double)3/5) };

   double c[3] = { (double)5/9 , (double)8/9 , (double)5/9 };
   double soma = 0;

   int i;

   for( i = 0 ; i < 3 ; i++ )
      soma += c[i]*TransformaQuadratura(a,b,x[i],f);

   return soma;
}

/* Corpo das funções encapsuladas pelo módulo */

double TransformaQuadratura( double a , double b , double t , double (*f) (double x) )
{
   return (*f)(( (b-a)*t + (b+a) )/2) * (b-a)/2;
}
