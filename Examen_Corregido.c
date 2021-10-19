#include <stdio.h>
#include <string.h>
#include <conio.h>

#define M 2
#define N 2
#define COL_ESTATURA 0
#define COL_SUELDO 0


typedef int clave[N];
typedef char nombre[N][20];
typedef float datos[N][M];

void capturaDatos(clave a, nombre b, datos c );
int buscaEmpleadoMasAlto(datos c);
void ordenaEmpleadosPorSueldo(clave a, nombre b, datos c);
void imprimeDatos(clave a, nombre b, datos c);

int main()
{
    int posicionMasAlto;

    clave a;
    nombre b ;
    datos c;

    capturaDatos(a,b,c);

    posicionMasAlto = buscaEmpleadoMasAlto(c);

    ordenaEmpleadosPorSueldo(a,b,c);

    imprimeDatos(a,b,c);

    printf("Nombre del empleado mas alto es: %s\n", b[posicionMasAlto]);
    printf("Y su estatura es: %f\n", c[posicionMasAlto][COL_ESTATURA]);

    getch();
    return 0 ;
}

void capturaDatos(clave a, nombre b, datos c )
{
    int numEmpleado, n = 1;

    for (numEmpleado = 0; numEmpleado < N; numEmpleado++)
    {
        printf("***Empleado no. %d*** \n", n);

            printf("Clave[%d]: ", numEmpleado + 1);
            scanf("%d", &a[numEmpleado]);

            printf("Nombre[%d]: ", numEmpleado + 1);
            scanf("%s", b[numEmpleado]);

            printf("Estaura[%d]: ", numEmpleado + 1);
            scanf("%f", &c[numEmpleado][0]);

            printf("Sueldo[%d]: ", numEmpleado + 1);
            scanf("%f", &c[0][numEmpleado]);

        n++;
        printf("\n");
        
    }

    
}

int buscaEmpleadoMasAlto(datos c)
{
    int empleado;
    int posicion = 0;
    float mayor = c[0][0];

    for(empleado = 0; empleado < N; empleado++ )
    {
        if(c[empleado][0] > mayor)
        {
            mayor = c[empleado][0];
            posicion = empleado;
        }
    }

    return posicion;
}

void ordenaEmpleadosPorSueldo(clave a, nombre b, datos c)
{
    int i, j;
    float aux;
    int auxClave;
    char auxNombre[20];

    for (i = 0; i < N-1; i++)
    {
        for(j = 0; j < N-1; j++)
        {
            if(c[j][COL_SUELDO] < c[j + 1][COL_SUELDO])
            {
                //Intercambio de sueldo
                aux = c[j][COL_SUELDO];
                c[j][COL_SUELDO] = c[j + 1][COL_SUELDO];
                c[j + 1][COL_SUELDO] = aux;

                //Intercambio de estatura
                aux = c[j][COL_ESTATURA];
                c[j][COL_ESTATURA] = c[j + 1][COL_ESTATURA];
                c[j + 1][COL_ESTATURA] = aux;

                //Intercambio de estatura
                auxClave = a[j];
                a[i] = a[j + 1];
                a[j + 1] = auxClave;

                //Intercambia nombre
                strcpy(auxNombre,b[j]);
                strcpy(b[j],b[j + 1]);
                strcpy(b[j + 1], auxNombre);

            }
        }
    }
}

void imprimeDatos(clave a, nombre b, datos c)
{
    int empleado;

    printf("Clave   Nombre  Estatura    Sueldo\n");

    for(empleado = 0; empleado < N; empleado++)
    {
        printf("%d\t\t", a[empleado]);
        printf("%s\t", b[empleado]);
        printf("%f\t", c[empleado][COL_ESTATURA]);
        printf("%f\t \n", c[empleado][COL_SUELDO]);

    }
}