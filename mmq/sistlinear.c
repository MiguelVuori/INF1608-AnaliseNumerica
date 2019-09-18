#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss (int n, double** A, double* b, double* x)
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
        /*
        for (k = j; k <= n-1; k++)
        {
            varTroca = A[j][k];
            A[j][k] = A[pivo][k];  //menos otimizado ERRO
            A[pivo][k] = varTroca;

        }
        */
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

void cholesky (int n, double** A)
{
	int i,k,j;

	for(k = 0; k <= n-1; k++)
	{	
		A[k][k] = sqrt(A[k][k]);

		for(i = k+1; i <= n-1; i++)
		{
			A[i][k] = A[i][k]/A[k][k]; /* vetor coluna(u) */
			A[k][i] = A[i][k]; /* vetor linha(u transposto) */
		}
		for (i = k+1; i <= n-1; i++)
			for (j = k+1; j <= n-1; j++)
				A[i][j] = A[i][j] - A[i][k] * A[k][j]; /* A[i][j] - u * transposta */
	}

}

void substituicoes (int n, double** A, double* b, double* x)
{
	int i,j;
	double y[n];

	for(i = 0; i < n; i++)
		y[i] = 0; 

	/* substituicao progressiva */
	for(i = 0;i <= n-1 ;i++)
	{
		double s = 0;

		for(j = i; j >= 0; j--)
			s = s + A[i][j] * y[j];

		y[i] = (b[i] - s) /A[i][i];
	}

	/* substituicao regressiva */
	for(i = n-1; i >= 0; i--)
    {
        double s = 0;

        for (j = i+1; j <= n-1; j++)
            s = s + A[i][j] * x[j];

        x[i] = (y[i] - s) /A[i][i];

    }
    
}