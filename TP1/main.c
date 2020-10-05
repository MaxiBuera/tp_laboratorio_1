#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

void pedirOperando(int operando, char message[]);

int main()
{

    int opcion=0;
    int primerOperando=0;
    int segundoOperando=0;
    int aux;


    do
    {

        pedirOperando(primerOperando,"\n1- Ingresar 1er operando (A=X)\n");
        pedirOperando(segundoOperando,"\n2- Ingresar 2do operando (B=Y)\n");
        printf("\n3- Calcular la suma (%d+%d)\n",primerOperando,segundoOperando);
        printf("2- Calcular la resta (%d-%d)\n",primerOperando,segundoOperando);
        printf("3- Calcular la division (%d/%d)\n",primerOperando,segundoOperando);
        printf("4- Calcular la multiplicacion (%d*%d)\n",primerOperando,segundoOperando);
        printf("5- Calcular el factorial (%d!) y (%d!)\n",primerOperando,segundoOperando);
        printf("6- Salir\n");

        aux=getValidInt("\n","\nNo Valida\n",&opcion,1,8,1);
        switch(opcion)
        {
            case 1:
                if(aux==0)
                    funcion_suma(primerOperando,segundoOperando);
                break;
            case 2:
                if(aux==0)
                    funcion_resta(primerOperando,segundoOperando);
                break;
            case 3:
                if(aux==0)
                    funcion_division(primerOperando,segundoOperando);
                break;
            case 4:
                if(aux==0)
                    funcion_multiplicacion(primerOperando,segundoOperando);
                break;
            case 5:
                if(aux==0){
                    funcion_factorial(primerOperando);
                    funcion_factorial(segundoOperando);
                }
                break;
        }
    }while(opcion!=6);

    return 0;
}

void pedirOperando(int operando, char message[]){

    getInt(&operando,"Ingrese Operando: ","Rango valido [-200000 - 200000]\n",-200000,200000);
}
