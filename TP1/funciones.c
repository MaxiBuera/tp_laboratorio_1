#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"


void funcion_suma(int primerOperando,int segundoOperando){

    int suma=primerOperando+segundoOperando;

    printf("\n%d + %d = %d\n",primerOperando,segundoOperando,suma);
}

void funcion_resta(int primerOperando,int segundoOperando){

    int resta=primerOperando-segundoOperando;

    printf("\n%d - %d = %d\n",primerOperando,segundoOperando,resta);
}

void funcion_division(int primerOperando,int segundoOperando){

    if((primerOperando == 0 && segundoOperando !=0) || (primerOperando != 0 && segundoOperando != 0)){

        float division=(float)primerOperando/segundoOperando;
        printf("\n%d / %d = %.2f\n",primerOperando,segundoOperando,division);
    }
    else{

         printf("\nOperacion no permitida\n");
    }
}

void funcion_multiplicacion(int primerOperando,int segundoOperando){

    int multiplicacion=primerOperando*segundoOperando;

    printf("\n%d * %d = %d\n",primerOperando,segundoOperando,multiplicacion);
}

void funcion_factorial(int primerOperando){

    int i;
    int factorial = primerOperando;

    if(primerOperando > 0){

        for(i=primerOperando-1;i>0;i--){

            factorial = factorial * i;
        }

        printf("\nFactorial de %d : %d\n",primerOperando,factorial);
    }

    else{

        printf("\nFactorial de Numero Negativo. No Valido\n");
    }

}
