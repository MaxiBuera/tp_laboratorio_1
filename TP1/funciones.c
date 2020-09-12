#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    clearStdin();
    scanf ("%[^\n]s", input);
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

	int retorno = -1;

	do{

		printf(message);
		scanf("%d",input);
		if(*input < lowLimit || *input > hiLimit){

			printf(eMessage);
		}

		retorno = 0;

	}while(*input < lowLimit || *input > hiLimit);



    return retorno;
}

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

void clearStdin(void)
{
    setbuf(stdin,NULL);
}
