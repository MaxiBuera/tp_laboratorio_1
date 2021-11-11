#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int retorno = -1;

    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];

    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL){

        fseek ( pFile , 32L , SEEK_SET );

        while(!feof(pFile)){

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas,sueldo);
            auxEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListEmployee,auxEmployee);
        }
        retorno=0;
    }


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            if(auxEmployee != NULL)
            {
                fread(auxEmployee, sizeof(Employee), 1, pFile);
                if(feof(pFile))
                {
                    retorno = -1;
                    break;
                }
                employee_setId(auxEmployee,proximoId());
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
        fclose(pFile);
        pFile = NULL;
        retorno = 0;
    }
    return retorno;
}
