#include <stdio.h>
#include <stdlib.h>

int FILAS;
int COLUMNAS;
void crammer (double mtx[][COLUMNAS],int *f,double *determinanteVariable );
void solucion (double *determimanteVariable,double mtx[][COLUMNAS]);
double Mtx_Determinante( double Aux[][COLUMNAS-1] );

int main()
{

    int n;
    printf("Ingrese el orden de la matriz: ");
    scanf("%d",&n);
    FILAS=n;
    COLUMNAS=n+1;
    printf("\nIngrese cada elemento de la matriz:\n\n");
    typedef enum { SUB_DETERMINANTE} STATE_T;
    int f=0;
    double determinanteVariable[FILAS];
    double matrizGeneral[n][n+1];
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=n; j++)
        {
            printf("matriz[%d][%d] : ", i,j);
            scanf("%lf",&matrizGeneral[i][j]);
        }
    }
    static STATE_T estado =SUB_DETERMINANTE;
    while(1)
    {
        switch (estado)
        {
            case SUB_DETERMINANTE:
                if(FILAS>f)
                {
                    crammer(matrizGeneral,&f,determinanteVariable);
                    estado = SUB_DETERMINANTE;
                }
                else
                {
                    solucion(determinanteVariable,matrizGeneral);
                    system("pause");
                    return 0;
                }
                break;
        }
    }
}

void crammer (double mtx[][COLUMNAS],int *f,double *determinanteVariable )
{

    double mtxPrueba[FILAS][COLUMNAS-1];
    for(int g=0; g<FILAS; g++)
    {
        for(int h=0; h<COLUMNAS-1; h++)
        {
            mtxPrueba[g][h]=mtx[g][h];
        }
    }
    for(int j=0; j<(COLUMNAS-1); j++)
    {
        mtxPrueba[j][*f]=mtx[j][COLUMNAS-1];
    }
    determinanteVariable[*f]= Mtx_Determinante(mtxPrueba);
    (*f)++;
}

void solucion (double *determimanteVariable,double mtx[][COLUMNAS])
{
    double detPrin=0;
    double mtxPrueba[FILAS][COLUMNAS-1];
    for(int g=0; g<FILAS; g++)
    {
        for(int h=0; h<COLUMNAS-1; h++)
        {
            mtxPrueba[g][h]=mtx[g][h];
        }
    }
    detPrin=Mtx_Determinante(mtxPrueba);
    double sol=0;
    int cont=0;
    for(int j=0; j<FILAS; j++)
    {
        sol=0;
        cont++;
        sol=(*(determimanteVariable+j)/(detPrin));
        printf("solucion %d: %.2f \n",cont,sol);
    }
}

double Mtx_Determinante( double mat[][COLUMNAS-1] )
{
    int d,i,j=0;
    double tmp = 0;
    for(d = 0; d< FILAS ; d++)
    {
        for(i = d+1; i < FILAS; i++)
        {
            tmp = mat[i][d]/mat[d][d];
            for(j = d; j< FILAS ; j++)
            {
                mat[i][j] -= tmp*mat[d][j];
            }
        }
    }
    double det = 1;
    for(d = 0; d < FILAS; d++)
    {
        det *= mat[d][d];
    }
    return det;
}
