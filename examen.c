#include <stdio.h>
#include <conio.h>

#define M 3
#define N 2
#define A 50

typedef int clave[M];
typedef char nombre[M][A];
typedef float arreglof[M][N];

void capturaDatos(clave a, nombre b, arreglof c);
int empleadoAlto(arreglof c, int *p2);
void seleccion(arreglof c);
void swap(int *x, int *y);
void imprimeDatos(clave a, nombre b, arreglof c);

int main()
{   
    int p1 = 0, p2 = 0;

    clave a;
    nombre b;
    arreglof c;

    capturaDatos(a,b,c);
    p1 = empleadoAlto(c, &p2);

    printf("El empleado más alto está en la ubicación: %d , %d", p1, p2);

    
    imprimeDatos(a,b,c);

    getch();
    return 0;
}

void capturaDatos(clave a, nombre b, arreglof c)
{
    int n = 0 ;

        for(int i = 0; i < M; i++)
        {
            
            printf("Empleado %d \n", n + 1);

            printf("Clave %d : ", i);
            scanf("%d", &a[i]);

            printf("Nombre %d : ", i);
            scanf("%s", b[i]); 

            for(int j = 0 ; j < N; j++)
            {
                printf("Estatura y Sueldo: ");
                scanf("%f", &c[i][j]);
            }

            n++;
        }

}

int empleadoAlto(arreglof c, int *p2)
{
    int alto = 0, p1;

    for(int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(c[i][j] > alto)
            {
                alto = c[i][j];
                p1 = i, *p2 = j;
            }
                
        }
        
    }
    return p1;
}

void burbuja(clave a, nombre b, arreglof c)
{
    int i, aux;

    for (i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
        {
            if(a[j] > a[j+1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}


void swap(int *x, int *y)
{
    int aux = *x;
    *x =*y;
    *y = aux;
}

void imprimeDatos(clave a, nombre b, arreglof c)
{

    int j;

    printf("Clave  Nombre  Estatura  Sueldo");
    for (int i = 0; i < M; i++)
    {
        
        
        printf("&d  %s  &f  &f", a[i], b[i], c[i][j], c[i][j+1]);
        
        j++;
    }
    
}
