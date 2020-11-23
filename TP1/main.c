#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"


int main()
{

    int opcion=0;
    int primerOperando=(char)'n'; //Los operandos estan inicializados de esta forma para poder mostrar el cambio de valor al visualizar el munu
    int segundoOperando=(char)'n';
    int aux;

    do
    {
        menu(primerOperando,segundoOperando);

        aux=getValidInt("\n","\nNo Valida\n",&opcion,1,4,1);
        switch(opcion)
        {
            case 1:
                if(aux==0)
                    primerOperando = pedirOperando(primerOperando,"\nIngresar 1er operando: ");
                break;
            case 2:
                if(aux==0)
                    segundoOperando = pedirOperando(segundoOperando,"\nIngresar 2do operando: ");
                break;
            case 3:
                if(aux==0 && primerOperando != 'n' && segundoOperando != 'n'){
                    funcion_suma(primerOperando,segundoOperando);
                    funcion_resta(primerOperando,segundoOperando);
                    funcion_division(primerOperando,segundoOperando);
                    funcion_multiplicacion(primerOperando,segundoOperando);
                    funcion_factorial(primerOperando);
                    funcion_factorial(segundoOperando);
                }
                else{
                    printf("\nOperando(s) no ingresado(s)\n");
                }
                break;
        }
    }while(opcion!=4);

    return 0;
}
