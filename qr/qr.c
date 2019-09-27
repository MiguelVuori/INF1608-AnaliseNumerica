#include <stdio.h>
#include "qr.h"
#include "matriz.h"



/* prototipos das funcoes encapsuladas plo modulo */
static void multcv (int n, double c, double * v, double * v2);
static void subvv(int n, double * v1, double * v2);
static void gauss2(int n, double** A, double* b, double* x);

void QR (int m, int n, double** A, double** Q, double** R)
{
    double* w, **QT = matcria(n,m), **AT = matcria(n,m),
    *RijQi = vetcria(m);

    transposta (m, n, A, AT);

    for(int j = 0; j < n; j++)
    {
        w = AT[j];

        for(int i = 0;i < j; i++)
        {
            R[i][j] = escalar (n, QT[i], w);
            multcv(m,R[i][j],QT[i],RijQi);
            subvv(m, w, RijQi);
        }
        R[j][j] = norma2(m,w);
        multcv(m, 1/R[j][j], w, QT[j]); 
    }
    transposta(n,m,QT,Q);

    matlibera (n, AT);
    matlibera (n, QT);
    vetlibera(RijQi);

}

double mmqQR (int m, int n, double** Q, double** R, double* b, double* x)
{
    double **Q2 = matcria(m,m),**Q2T = matcria(m,m), **R2 = matcria(m,n),
    *Q2Tb = vetcria(m),*d = vetcria(n);
    
    /* transformando Q2 em uma matriz quadrada adicionando colunas e adicionando zeros nas linhas de R2*/
    for(int i = 0; i < m; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if(j >= n)
            {
                Q2[i][j] = 0;
            }
            else
            {
                Q2[i][j] = Q[i][j];
                if (i < n)
                {
                    R2[i][j] = R[i][j];
                }
                else
                {
                    R2[i][j] = 0;
                }
                
            }

        }
    }

    transposta (m, m, Q2, Q2T);
    multmv (m,m,Q2T,b,Q2Tb);
 

    for(int i = 0; i < n; i++)
    {
        d[i] = Q2Tb[i];
    }

    gauss2(n,R,d,x);

    matlibera(m,Q2);
    matlibera(m,R2);
    matlibera(m,Q2T);
    vetlibera(Q2Tb);
    vetlibera(d);

    return 0;
}

/* funcoes encapsulados */
void multcv(int n, double c, double * v, double * v2)
{
    for(int i =0; i < n; i++)
        v2[i] = v[i] * c;
}

void subvv(int n, double * v1, double * v2)
{
    for(int i = 0; i < n; i++)
        v1[i] = v1[i] - v2[i];
}

void gauss2 (int n, double** A, double* b, double* x)
{
    int i = 0,j = 0;

    for (j = 0;j <= n - 2; j++ )
    {
        int pivo = j;
        int k;
        double varTroca;
        double* endTroca;

        /* Inicio do Pivotamento */
        for (k = j+1;k <= n-1; k++)
            if (fabs(A[k][j]) > fabs(A[pivo][j]))
                pivo = k;

        /* Troca as linhas j e p */

        endTroca = A[j];
        A[j] = A[pivo];
        A[pivo] = endTroca;

        varTroca = b[pivo];
        b[pivo] = b[j];
        b[j] = varTroca;
        /* Fim do Pivotamento */

        /* Inicio da eliminacao */
        for (i = j + 1; i <= n-1; i++)
        {
            double f = A[i][j]/A[j][j];
            for(k = j; k <= n-1; k++)
            {
                A[i][k] = A[i][k] - (A[j][k] * f);
            }
            b[i] = b[i] - (b[j] * f); 
        }

        /* Fim da eliminacao */
    }

    /* Inicio da substituicao regressiva */
    for(i = n-1; i >= 0; i--)
    {
        double s = 0;

        for (j = i+1; j <= n-1; j++)
            s = s + A[i][j] * x[j];

        x[i] = (b[i] - s) /A[i][i];

    }
    /* Fim da substituicao regressiva */
}

