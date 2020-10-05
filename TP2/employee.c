#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "employee.h"
#define SECTOR 10
#define MINSALARY 0
#define MAXSALARY 100000
#define OCCUPIED 0
#define FREE 1

static int nextId();

void employee_normalizeTextString(char textString[]){

    int j,i;
    i = strlen(textString);

    for(j=0;j<i;j++){

        if(j==0){

            textString[j] = toupper(textString[j]);
        }
        else{

            textString[j] = tolower(textString[j]);
        }
    }
}

int employee_initEmployees(eEmployee* arrayEmployees, int limit){

    int error = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        error = 0;
        for(i=0;i<limit;i++)
        {
            arrayEmployees[i].id = -1;
            strcpy(arrayEmployees[i].name,"");
            strcpy(arrayEmployees[i].lastname,"");
            arrayEmployees[i].salary = 0;
            arrayEmployees[i].sector = -1;
            arrayEmployees[i].isEmpty = FREE;

        }
    }
    return error;
}

int employee_addEmployees(eEmployee* arrayEmployees, int limit, int index){

    int error = -1;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;
    int id;

    if(limit > 0 && arrayEmployees != NULL){

        error = -2;
        id = nextId();

        if(getStringLetras("Ingrese nombre: ",nameAux)){

            if(getStringLetras("Ingrese apellido: ",lastnameAux)){

                if(!getValidFloat("Ingrese salario: ","\nError\n",&salaryAux,MINSALARY,MAXSALARY,2)){

                    if(!getValidInt("Ingrese sector: ","\nError (Sector 1-10)\n",&sectorAux,0,SECTOR,2)){

                        employee_normalizeTextString(nameAux);
                        strcpy(arrayEmployees[index].name,nameAux);

                        employee_normalizeTextString(lastnameAux);
                        strcpy(arrayEmployees[index].lastname,lastnameAux);

                        arrayEmployees[index].salary = salaryAux;
                        arrayEmployees[index].sector = sectorAux;
                        arrayEmployees[index].isEmpty = OCCUPIED;
                        arrayEmployees[index].id = id;
                        error = 0;
                    }
                }
            }
        }
    }

    if(error != 0){

        printf("\nError\n");
    }

    return error;

}

int employee_searchForFreePosition(eEmployee* arrayEmployees,int limit)
{
    int error = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        error = -2;
        for(i=0;i<limit;i++)
        {
            if(arrayEmployees[i].isEmpty == FREE)
            {
                error = i;
                break;
            }
        }
    }
    return error;
}

int employee_forceAdd(eEmployee* arrayEmployees,int limit,char* name,char* lastname, float salary,int sector)
{
    int error = -1;
    int i;

    if(limit > 0 && arrayEmployees != NULL)
    {
        i = employee_searchForFreePosition(arrayEmployees,limit);
        if(i >= 0)
        {
            error = 0;
            strcpy(arrayEmployees[i].name,name);
            strcpy(arrayEmployees[i].lastname,lastname);
            arrayEmployees[i].salary = salary;
            arrayEmployees[i].sector = sector;
            //------------------------------
            //------------------------------
            arrayEmployees[i].id = nextId();
            arrayEmployees[i].isEmpty = OCCUPIED;
        }
        error = 0;
    }
    return error;
}

int employee_printEmployees(eEmployee* arrayEmployees,int limit){

    int error = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        error = 0;
        printf("\n\tNombre\t\tApellido\tID\tSector\tSalario");
        printf("\n\t--------------------------------------------------------");
        for(i=0;i<limit;i++)
        {
        	if(!arrayEmployees[i].isEmpty)
            {

           		printf("\n\t%s\t\t%s\t\t%d\t%d\t%.2f",arrayEmployees[i].name,arrayEmployees[i].lastname,arrayEmployees[i].id,arrayEmployees[i].sector,arrayEmployees[i].salary);
           	}
        }
    }
    return error;
}

int employee_findEmployeeById(eEmployee* arrayEmployees,int limit, int id)
{
    int error = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        error = -2;
        for(i=0;i<limit;i++)
        {
            if(arrayEmployees[i].isEmpty == OCCUPIED && arrayEmployees[i].id == id)
            {
                error = i;
                break;
            }
        }
    }
    return error;
}

int employee_showEmployeeUpdated(eEmployee* arrayEmployees,int limit){

    int error = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        error = 0;
        printf("\n\tNombre\t\tApellido\tID");
        for(i=0;i<limit;i++)
        {
        	if(!arrayEmployees[i].isEmpty)
            {

           		printf("\n\t%s\t\t%s\t\t%d",arrayEmployees[i].name,arrayEmployees[i].lastname,arrayEmployees[i].id);
        	}
        }
    }
    printf("\n\n");
    return error;
}

int employee_updateEmployees(eEmployee* arrayEmployees, int limit,int index){

    int indice;
    int error = -1;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;


    indice = employee_findEmployeeById(arrayEmployees,limit,index);
    if(indice >= 0)
    {
        error = 0;
        if(getStringLetras("Ingrese nombre: ",nameAux)){

            if(getStringLetras("Ingrese nombre: ",lastnameAux)){

                if(!getValidFloat("Ingrese salario: ","\nError",&salaryAux,MINSALARY,MAXSALARY,2)){

                    if(!getValidInt("Ingrese sector: ","\nError",&sectorAux,0,SECTOR,2)){

                        strcpy(arrayEmployees[index].name,nameAux);
                        strcpy(arrayEmployees[index].lastname,lastnameAux);
                        arrayEmployees[index].salary = salaryAux;
                        arrayEmployees[index].salary = sectorAux;
                        arrayEmployees[index].isEmpty = OCCUPIED;
                        error = 0;
                    }
                }
            }
    }
    }
    else{

        printf("\nID no encontrado");
    }
    return error;
}

int employee_removeEmployee(eEmployee* arrayEmployees, int limit,int index){

    int error = -1;
    int indice;
    indice = employee_findEmployeeById(arrayEmployees,limit,index);
    if(indice >= 0)
    {
        error = 0;
        arrayEmployees[indice].isEmpty = FREE;
    }
    else{

        printf("\nID no encontrado");
    }
    return error;
}

int employee_orderByLastName(eEmployee* arrayEmployees,int limit, int order)
{
    int error = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limit > 0 && arrayEmployees != NULL)
    {
        error = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limit-1;i++)
            {
                    if(arrayEmployees[i].isEmpty == OCCUPIED && arrayEmployees[i+1].isEmpty == OCCUPIED )
                    {
                        if((strcmp(arrayEmployees[i].lastname,arrayEmployees[i+1].lastname) > 0 && !order) || (strcmp(arrayEmployees[i].lastname,arrayEmployees[i+1].lastname) < 0 && order)) //<------------
                        {
                            auxiliar = arrayEmployees[i];
                            arrayEmployees[i] = arrayEmployees[i+1];
                            arrayEmployees[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return error;
}

int employee_orderBySector(eEmployee* arrayEmployees,int limit, int order)
{
    int error = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limit > 0 && arrayEmployees != NULL)
    {
        error = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limit-1;i++)
            {
                    if(arrayEmployees[i].isEmpty == OCCUPIED && arrayEmployees[i+1].isEmpty == OCCUPIED )
                    {
                        if((arrayEmployees[i].sector > arrayEmployees[i+1].sector && !order) || (arrayEmployees[i].sector < arrayEmployees[i+1].sector && order)) //<------------
                        {
                            auxiliar = arrayEmployees[i];
                            arrayEmployees[i] = arrayEmployees[i+1];
                            arrayEmployees[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return error;
}

float totalSalaries(eEmployee* arrayEmployees,int limit){

    int i;
    float total = 0;

    if(limit > 0 && arrayEmployees != NULL){

        for(i=0;i<limit;i++){

            total = total + arrayEmployees[i].salary;
        }
    }

    return total;
}

int empleadosActuales(eEmployee* arrayEmployees,int limit){

    int i;
    int cantidadEmpleados = 0;

    if(limit > 0 && arrayEmployees != NULL){

        for(i=0;i<limit;i++){

            if(arrayEmployees[i].isEmpty == 0){

                cantidadEmpleados++;
            }
        }
    }

    return cantidadEmpleados;
}

float employee_averageSalary(eEmployee* arrayEmployees,int limit){

    float total,averageSalary;
    int cantidadEmpleados;

    if(limit > 0 && arrayEmployees != NULL){

        total = totalSalaries(arrayEmployees,limit);
        cantidadEmpleados = empleadosActuales(arrayEmployees,limit);

        averageSalary = total / cantidadEmpleados;

        printf("\n\n\tTotal sueldos: %.2f",total);
        printf("\n\tSueldo Promedio: %.2f",averageSalary);
    }

    return averageSalary;
}

int employee_aboveAverage(eEmployee* arrayEmployees,int limit, float averageSalary){

    int error = -1;
    int i;
    int cantidadEmpleadosMayorAlPromedio = 0;

    if(limit > 0 && arrayEmployees != NULL){

        error = 0;

        for(i=0;i<limit;i++){

            if(arrayEmployees[i].salary > averageSalary){

                cantidadEmpleadosMayorAlPromedio++;
            }
        }
    }

    printf("\n\n\tCantidad de empleados cuyos salarios superan el promedio: %d empleado(s)",cantidadEmpleadosMayorAlPromedio);

    return error;
}



static int nextId()
{
    static int lastId = 0;
    lastId++;
    return lastId;
}
