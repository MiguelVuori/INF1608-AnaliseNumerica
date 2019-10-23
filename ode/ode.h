#include <stdio.h>

double PontoMedio (double t0,
                double t1,
                double h, 
                double y0, 
                double (*f) (double t, 
                double y));

double PontoMedioAdapt (double t0, 
                        double t1, 
                        double h0, 
                        double y0,
                        double (*f) (double t, double y), 
                        double tol);