#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define SECTOR 10
#define MINSALARY 1
#define MAXSALARY 300000
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

    int returnValue = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = 0;
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
    return returnValue;
}

int employee_addEmployee(eEmployee* arrayEmployees, int limit, int index){

    int returnValue = -1;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;
    int id;

    if(limit > 0 && arrayEmployees != NULL){

        returnValue = -2;
        id = nextId();

        if(getStringLetras("\nIngrese nombre: ",nameAux)){

            if(getStringLetras("Ingrese apellido: ",lastnameAux)){

                if(!getValidFloat("Ingrese salario: ","\nError\n",&salaryAux,MINSALARY,MAXSALARY,2)){

                    if(!getValidInt("Ingrese sector (Sector 1-10): ","\nError\n",&sectorAux,0,SECTOR,2)){

                        employee_normalizeTextString(nameAux);
                        strcpy(arrayEmployees[index].name,nameAux);

                        employee_normalizeTextString(lastnameAux);
                        strcpy(arrayEmployees[index].lastname,lastnameAux);

                        arrayEmployees[index].salary = salaryAux;
                        arrayEmployees[index].sector = sectorAux;
                        arrayEmployees[index].isEmpty = OCCUPIED;
                        arrayEmployees[index].id = id;
                        printf("\n\tEmpleado Agregado...");
                        returnValue = 0;
                    }
                }
            }
        }
    }

    if(returnValue != 0){

        printf("\nError\n");
    }

    return returnValue;

}

int employee_searchForFreePosition(eEmployee* arrayEmployees,int limit)
{
    int returnValue = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = -2;
        for(i=0;i<limit;i++)
        {
            if(arrayEmployees[i].isEmpty == FREE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int employee_forceAdd(eEmployee* arrayEmployees,int limit,char* name,char* lastname, float salary,int sector)
{
    int returnValue = -1;
    int i;

    if(limit > 0 && arrayEmployees != NULL)
    {
        i = employee_searchForFreePosition(arrayEmployees,limit);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayEmployees[i].name,name);
            strcpy(arrayEmployees[i].lastname,lastname);
            arrayEmployees[i].salary = salary;
            arrayEmployees[i].sector = sector;
            //------------------------------
            //------------------------------
            arrayEmployees[i].id = nextId();
            arrayEmployees[i].isEmpty = OCCUPIED;
        }
        returnValue = 0;
    }
    return returnValue;
}

int employee_printEmployees(eEmployee* arrayEmployees,int limit){

    int returnValue = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = 0;
        printf("\n\tNombre\t\tApellido\tID\tSector\t  Salario");
        printf("\n\t----------------------------------------------------------");
        for(i=0;i<limit;i++)
        {
        	if(!arrayEmployees[i].isEmpty)
            {

           		printf("\n%16s %14s %9d %9d %14.2f",arrayEmployees[i].name,arrayEmployees[i].lastname,arrayEmployees[i].id+1,arrayEmployees[i].sector,arrayEmployees[i].salary);
           	}
        }
    }
    return returnValue;
}

int employee_findEmployeeById(eEmployee* arrayEmployees,int limit, int id)
{
    int returnValue = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = -2;
        for(i=0;i<limit;i++)
        {
            if(arrayEmployees[i].isEmpty == OCCUPIED && arrayEmployees[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int employee_showEmployeeUpdated(eEmployee* arrayEmployees,int limit){

    int returnValue = -1;
    int i;
    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = 0;
        printf("\n\tNombre\t\tApellido\tID");
        printf("\n\t----------------------------------");
        for(i=0;i<limit;i++)
        {
        	if(!arrayEmployees[i].isEmpty)
            {

           		printf("\n%16s %14s %9d",arrayEmployees[i].name,arrayEmployees[i].lastname,arrayEmployees[i].id+1);
        	}
        }
    }
    printf("\n\n");
    return returnValue;
}

void employee_menuUpdateEmployee(eEmployee* arrayEmployees, int index){

    int opc;
    char nameAux[51];
    char lastNameAux[51];
    float salaryAux;
    int sectorAux;

    printf("\nEmpleado a Modificar: %s %s",arrayEmployees[index].name,arrayEmployees[index].lastname);

    do{

        getValidInt("\n\n\t1.Modificar Nombre\n\t2.Modificar Apellido\n\t3.Modificar Salario\n\t4.Modificar Sector\n\t5.Listo\n","\nNo valida\n",&opc,1,5,1);
        switch(opc)
        {
            case 1:
                if(getStringLetras("\nIngrese nombre: ",nameAux)){

                    employee_normalizeTextString(nameAux);
                    strcpy(arrayEmployees[index].name,nameAux);
                    printf("\nNombre Modificado...");
                }
                break;
            case 2:
                if(getStringLetras("Ingrese apellido: ",lastNameAux)){

                    employee_normalizeTextString(lastNameAux);
                    strcpy(arrayEmployees[index].lastname,lastNameAux);
                    printf("\nApellido Modificado...");
                }
                break;
            case 3:
                if(!getValidFloat("Ingrese salario: ","\nError",&salaryAux,MINSALARY,MAXSALARY,2)){

                    arrayEmployees[index].salary = salaryAux;
                    printf("\nSalario Modificado...");
                }
                break;
            case 4:
                if(!getValidInt("Ingrese sector: ","\nError",&sectorAux,0,SECTOR,2)){

                    arrayEmployees[index].sector = sectorAux;
                    printf("\nSector Modificado...");
                }
                break;
        }
    }while(opc != 5);
}

int employee_updateEmployee(eEmployee* arrayEmployees, int limit,int index){

    int i;
    int returnValue = -1;

    i = employee_findEmployeeById(arrayEmployees,limit,index);
    if(i >= 0)
    {
        employee_menuUpdateEmployee(arrayEmployees,i);
        arrayEmployees[i].isEmpty = OCCUPIED;
        returnValue = 0;
    }
    else{

        printf("\nError. Vuelva a intentar");
    }
    return returnValue;
}

int employee_removeEmployee(eEmployee* arrayEmployees, int limit,int index){

    int returnValue = -1;
    int i;
    char confirm;
    i = employee_findEmployeeById(arrayEmployees,limit,index);
    if(i >= 0)
    {
        printf("\nEmpleado a eliminar: %s %s",arrayEmployees[i].name,arrayEmployees[i].lastname);
        confirm = getChar("\n¿Desea eliminar el empleado? [s/n]: ");
        if(confirm == 's' || confirm == 'S'){
            arrayEmployees[i].isEmpty = FREE;
            printf("\n\n\tEmpleado Eliminado...");
            returnValue = 0;
        }
        else if(confirm == 'n' || confirm == 'N'){

            printf("\n\tEmpleado No Eliminado...");
            return returnValue;
        }
    }
    else{

        printf("\nID no encontrado");
    }
    return returnValue;
}

int employee_orderByLastName(eEmployee* arrayEmployees,int limit, int order)
{
    int returnValue = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = 0;
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

    return returnValue;
}

int employee_orderBySector(eEmployee* arrayEmployees,int limit, int order)
{
    int returnValue = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limit > 0 && arrayEmployees != NULL)
    {
        returnValue = 0;
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

    return returnValue;
}

float totalSalaries(eEmployee* arrayEmployees,int limit){

    int i;
    float total = 0;

    if(limit > 0 && arrayEmployees != NULL){

        for(i=0;i<limit;i++){

            if(arrayEmployees[i].isEmpty == OCCUPIED){

                total = total + arrayEmployees[i].salary;
            }
        }
    }

    return total;
}

int currentEmployees(eEmployee* arrayEmployees,int limit){

    int i;
    int totalEmployees = 0;

    if(limit > 0 && arrayEmployees != NULL){

        for(i=0;i<limit;i++){

            if(arrayEmployees[i].isEmpty == 0){

                totalEmployees++;
            }
        }
    }

    return totalEmployees;
}

float employee_averageSalary(eEmployee* arrayEmployees,int limit){

    float total,averageSalary;
    int totalEmployees;

    if(limit > 0 && arrayEmployees != NULL){

        total = totalSalaries(arrayEmployees,limit);
        totalEmployees = currentEmployees(arrayEmployees,limit);

        averageSalary = total / totalEmployees;

        printf("\n\n\tTotal sueldos: %.2f",total);
        printf("\n\tSueldo Promedio: %.2f",averageSalary);
    }

    return averageSalary;
}

int employee_aboveAverage(eEmployee* arrayEmployees,int limit, float averageSalary){

    int returnValue = -1;
    int i;
    int employeesGreaterThanAverage = 0;

    if(limit > 0 && arrayEmployees != NULL){

        returnValue = 0;

        for(i=0;i<limit;i++){

            if(arrayEmployees[i].isEmpty == OCCUPIED){
                if(arrayEmployees[i].salary > averageSalary){

                    employeesGreaterThanAverage++;
                }
            }
        }
    }

    printf("\n\n\tCantidad de empleados cuyos salarios superan el promedio: %d empleado(s)",employeesGreaterThanAverage);

    return returnValue;
}



static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}
