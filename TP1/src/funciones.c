#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"

/**
* \brief Realiza la suma de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_suma(int primerOperando,int segundoOperando){

    int suma=primerOperando+segundoOperando;

    printf("\na) El resultado de %d + %d es: %d\n",primerOperando,segundoOperando,suma);
}

/**
* \brief Realiza la resta de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_resta(int primerOperando,int segundoOperando){

    int resta=primerOperando-segundoOperando;

    printf("\nb) El resultado de %d - %d es: %d\n",primerOperando,segundoOperando,resta);
}

/**
* \brief Realiza la division de los parametros ingresados. Validando la division cuando el
         segundo operando es 0
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_division(int primerOperando,int segundoOperando){

    if((primerOperando == 0 && segundoOperando !=0) || (primerOperando != 0 && segundoOperando != 0)){

        float division=(float)primerOperando/segundoOperando;
        printf("\nc) El resultado de %d / %d es %.2f\n",primerOperando,segundoOperando,division);
    }
    else{

         printf("\nNo es posible dividir por 0\n");
    }
}

/**
* \brief Realiza la multiplicacion de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_multiplicacion(int primerOperando,int segundoOperando){

    int multiplicacion=primerOperando*segundoOperando;

    printf("\nd) El resultado de %d * %d es %d\n",primerOperando,segundoOperando,multiplicacion);
}

/**
* \brief Realiza el factorial del primer operando ingresado
* \param operando Primer operando de la cuenta
* \return -
*
*/
void funcion_factorial(int operando){

    int i;
    int factorial = operando;

    if(operando > 0){

        for(i=operando-1;i>0;i--){

            factorial = factorial * i;
        }

        printf("\nFactorial de %d es %d\n",operando,factorial);
    }

    else{

        printf("\nFactorial de Numero Negativo. No Valido\n");
    }

}
