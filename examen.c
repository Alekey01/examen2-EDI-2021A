#include <stdio.h>
#include <conio.h>

#define M 4
#define N 2
#define A 50

typedef int clave[M];
typedef char nombre[A];
typedef float arreglof[M][N];

void capturaDatos(clave a, nombre b, arreglof c);
int empleadoAlto(arreglof c, int *p2);
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
            scanf("%c", b[i]); 

            for(int j = 0 ; j < N; j++)
            {
                printf("Estatura y Edad: ");
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

void imprimeDatos(clave a, nombre b, arreglof c)
{

    int j;

    printf("Clave  Nombre  Estatura  Sueldo");
    for (int i = 0; i < M; i++)
    {
        
        
        printf("&d  %c  &f  &f", a[i], b[i], c[i][j], c[i][j+1]);
        
        j++;
    }
    

}
