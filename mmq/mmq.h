#include <stdio.h>
#include "sistlinear.h"
#include "matriz.h"

double MMQ (int m, int n, double** A, double* b, double* x);

double periodico (int n, double* t, double* v, double* c);

double previsao (double* c, double t);