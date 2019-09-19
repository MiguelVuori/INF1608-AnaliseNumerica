#include <stdio.h>
#include "sistlinear.h"
#include "matriz.h"
#include "math.h"
#define Pi 3.14159265359

/*
 A funcao resolve o sistema Ax = b pelo metodo dos minimos quadrados.
sendo m o numero de linhas da matriz A e n o numero de colunas. A solucao encontrada
preeenche o vetor x de dimensao n. A funcao retorna a norma 2 do erro.
*/

double MMQ (int m, int n, double** A, double* b, double* x);

/*
Ajusta um modelo periodico do tipo : v = c0 + c1t + c2 sin 2πt + c3 cos 2πt + c4 cos 4πt.
n eh o numero de pontos (t,v).
*/

double periodico (int n, double* t, double* v, double* c);

/* Retorna a previsao do modelo periodico */

double previsao (double* c, double t);