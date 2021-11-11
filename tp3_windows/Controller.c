#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

/** \brief  Formatea la cadena pasada por parametro (primer letra mayuscula)
 *
 * \param   cadena a formatear
 * \return
 *
 */
void controller_normalizeFields(char field[]){

    int j,i;
    i = strlen(field);

    for(j=0;j<i;j++){

        if(j==0){

            field[j] = toupper(field[j]);
        }
        else{

            field[j] = tolower(field[j]);
        }
    }
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;


    FILE* pFile = NULL;
    pFile = fopen(path,"r");

    if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0){

        retorno = 0;
    }


    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    int retorno = -1;

    FILE* pFile = NULL;
    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL){


        retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    fclose(pFile);


    return retorno;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    char nombre[128];
    char nombreAux[128];
    int horasTrabajadas;
    int sueldo;

    Employee* auxEmployee;

    if(pArrayListEmployee != NULL && (pArrayListEmployee->size) >= 0){

        if(!getValidString("\nNombre: ","Error\n","Overflow",nombreAux,128,2))
        {
            if(!getValidInt("Horas Trabajadas: ","Error\n",&horasTrabajadas,1,500,2))
            {
                if(!getValidInt("Sueldo: ","Error\n",&sueldo,1,999999,2))
                {

                    controller_normalizeFields(nombreAux);
                    strcpy(nombre,nombreAux);


                    auxEmployee = employee_newParametros2(nombre,horasTrabajadas,sueldo);
                    ll_add(pArrayListEmployee,auxEmployee);
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    int i;
    int idEmpleado;
    char nombre[128];
    char nombreAux[128];
    int horasTrabajadas;
    int sueldo;
    int opc;
    int opcAux=0;

    Employee* auxEmployee=NULL;
    Employee* auxEmployeeNuevo=NULL;


    if(pArrayListEmployee != NULL){

        if(!getValidInt("\nIngrese ID: ","Error\n",&idEmpleado,1,ll_len(pArrayListEmployee),2))
        {

            for(i=0;i<ll_len(pArrayListEmployee);i++){

                auxEmployee = ll_get(pArrayListEmployee, i);

                if(auxEmployee->id == idEmpleado){

                    printf("\nModificando:    ID: %d  -  Nombre: %s\n\n",auxEmployee->id,auxEmployee->nombre);

                    strcpy(nombre,auxEmployee->nombre);
                    horasTrabajadas=auxEmployee->horasTrabajadas;
                    sueldo=auxEmployee->sueldo;


                    do{

                        getValidInt("\n\t1.Modificar Nombre\n\t2.Modificar Horas Trabajadas\n\t3.Modificar Salario\n\t4.Listo\n","\nNo valida\n",&opc,1,4,1);
                        switch(opc)
                        {
                            case 1:

                                if(!getValidString("Nombre: ","Error\n","Overflow",nombreAux,128,2)){

                                    controller_normalizeFields(nombreAux);
                                    strcpy(nombre,nombreAux);
                                    opcAux=1;
                                    printf("\nNombre Modificado...\n");
                                }
                                break;
                            case 2:
                                if(!getValidInt("Horas Trabajadas: ","Error\n",&horasTrabajadas,1,500,2)){
                                    opcAux=1;
                                    printf("\nHoras trabajadas Modificadas...\n");
                                }
                                break;
                            case 3:
                                if(!getValidInt("Sueldo: ","Error\n",&sueldo,1,999999,2)){
                                    opcAux=1;
                                    printf("\nSueldo Modificado...\n");
                                }
                                break;
                            }
                    }while(opc != 4);

                    auxEmployeeNuevo = employee_newParametros3(idEmpleado,nombre,horasTrabajadas,sueldo);
                    ll_set(pArrayListEmployee,idEmpleado-1,auxEmployeeNuevo);

                    if(opcAux!=0){
                       printf("\nEmpleado Modificado...");
                    } else{
                        printf("\nEmpleado No Modificado...");
                    }

                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int idEliminar;
    char confirmar;

    Employee* auxEmployee=NULL;

    if(pArrayListEmployee != NULL){

        if(!getValidInt("\nIngrese ID: ","Error\n",&idEliminar,1,ll_len(pArrayListEmployee),2))
        {

            for(i=0;i<ll_len(pArrayListEmployee);i++){

                auxEmployee = ll_get(pArrayListEmployee, i);

                if(auxEmployee->id == idEliminar){

                    printf("\nEliminar: ID: %d  -  Nombre: %s",auxEmployee->id,auxEmployee->nombre);

                    if(!getOpcion(&confirmar,"\n\ty/n: ","\nOpcion no valida",'y','n')){

                        if(confirmar == 'y'){

                            ll_remove(pArrayListEmployee,idEliminar-1);
                            printf("\nEmpleado Eliminado\n");
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    Employee* auxEmployee=NULL;

    system("cls");

    if(pArrayListEmployee != NULL){

        printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");

        for(i=0;i<ll_len(pArrayListEmployee);i++){

            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee,&id);
            employee_getNombre(auxEmployee,nombre);
            employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
            employee_getSueldo(auxEmployee,&sueldo);

            printf("%4d %18s %20d %20d\n",id,nombre,horasTrabajadas,sueldo);
            //printf("%s,",nombre);
        }
    }

    return 1;
}

/** \brief Listar empleados (solo con la columna id y nombre)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployeeId(LinkedList* pArrayListEmployee)
{

    int i;
    int id;
    char nombre[50];

    Employee* auxEmployee=NULL;

    system("cls");

    if(pArrayListEmployee != NULL){

        printf("\nLista de Empleados:\n\n");
        printf("%4s %18s \n", "ID:", "Nombre:");
        for(i=0;i<ll_len(pArrayListEmployee);i++){

            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee,&id);
            employee_getNombre(auxEmployee,nombre);

            printf("%4d %18s \n",id,nombre);
        }
    }

    return 1;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char nombre[50];
    char nombre2[50];
    int flagSwap;
    int i;
    int orden = 0;
    int flagAviso = 0;


    Employee* auxEmployee=NULL;
    Employee* auxEmployee2=NULL;
    Employee* auxSwap=NULL;

    if( pArrayListEmployee != NULL)
    {

        retorno = 0;
        do
        {
            if(flagAviso == 0){
                printf("\nOrdenando Lista ..\n");
                flagAviso = 1;
            }

            flagSwap = 0;
            for(i=0;i<ll_len(pArrayListEmployee) -1;i++)
            {

                auxEmployee = ll_get(pArrayListEmployee, i);
                auxEmployee2 = ll_get(pArrayListEmployee, i+1);

                if(auxEmployee != NULL && auxEmployee2 != NULL )
                {

                    employee_getNombre(auxEmployee,nombre);
                    employee_getNombre(auxEmployee2,nombre2);


                        if((strcmp(auxEmployee->nombre,auxEmployee2->nombre) > 0 && !orden) || (strcmp(auxEmployee->nombre,auxEmployee2->nombre) < 0 && orden)) //<------------
                        {
                            auxSwap = auxEmployee;
                          //printf("\n%s",auxSwap->nombre);

                            auxEmployee = auxEmployee2;
                            auxEmployee2 = auxSwap;

                            ll_set(pArrayListEmployee,i,auxEmployee);
                            ll_set(pArrayListEmployee,i+1,auxEmployee2);


                            flagSwap = 1;
                        }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    int idStr;
    char nombreStr[51];
    int horasTrabajadasStr;
    int sueldoStr;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Nombre,Horas trabajadas,Salario\n");
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, &idStr);
                employee_getNombre(auxEmployee, nombreStr);
                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadasStr);
                employee_getSueldo(auxEmployee, &sueldoStr);

                fprintf(pFile, "%d,%s,%d,%d\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

