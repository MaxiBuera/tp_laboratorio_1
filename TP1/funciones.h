#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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
