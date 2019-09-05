#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* vetcria (int n);

void vetlibera (double* v);

double escalar (int n, double* v, double* w);

double norma2 (int n, double* v);

double** matcria (int m, int n);

void matlibera (int m, double** A);

void transposta (int m, int n, double** A, double** T);

void multmv (int m, int n, double** A, double* v, double* w);

void multmm (int m, int n, int q, double** A, double** B, double** C);

void matexibe (int m, int n,double** A);