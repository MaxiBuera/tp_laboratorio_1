#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);

/**
* \brief Solicita un numero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Realiza la suma de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_suma(int primerOperando,int segundoOperando);

/**
* \brief Realiza la resta de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_resta(int primerOperando,int segundoOperando);

/**
* \brief Realiza la division de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_division(int primerOperando,int segundoOperando);

/**
* \brief Realiza la multiplicacion de los parametros ingresados
* \param primerOperando Primer operando de la cuenta
* \param segundoOperando Segundo operando de la cuenta
* \return -
*
*/
void funcion_multiplicacion(int primerOperando,int segundoOperando);

/**
* \brief Realiza el factorial del primer operando ingresado
* \param primerOperando Primer operando de la cuenta
* \return -
*
*/
void funcion_factorial(int primerOperando);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clearStdin(void);

#endif // FUNCIONES_H_INCLUDED
