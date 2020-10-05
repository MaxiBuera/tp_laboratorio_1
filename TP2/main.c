#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define OCCUPIED 0
#define FREE 1
#define EMPLOYEES 5 // 1000 empleados

int main()
{

    int menu;
    int index;
    int auxiliarId;
    int flag = 0;
    int flagAdd;
    float averageSalary;

    eEmployee arrayEmployees[EMPLOYEES];

    employee_initEmployees(arrayEmployees,EMPLOYEES);

    //Solo para testear
    employee_forceAdd(arrayEmployees,EMPLOYEES,"Pablo","Gimenez",20000,2);
    employee_forceAdd(arrayEmployees,EMPLOYEES,"Mariano","Alfonso",30000,1);


    do{

        getValidInt("\n\n1.Alta Empleado\n2.Modificar Empleado\n3.Baja Empleado\n4.Informar\n5.Salir\n","\nNo valida\n",&menu,1,5,1);
        switch(menu)
        {

            case 1:

                index = employee_searchForFreePosition(arrayEmployees,EMPLOYEES);
                if(index >= 0){

                    flagAdd = employee_addEmployees(arrayEmployees,EMPLOYEES,index);
                    if(flagAdd == 0)
                        flag = 1;
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 2:

                if(flag!=0){
                    employee_showEmployeeUpdated(arrayEmployees,EMPLOYEES);
                    getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLOYEES,2);
                    employee_updateEmployees(arrayEmployees,EMPLOYEES,auxiliarId);
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 3:

                //if(flag!=0){

                    getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLOYEES,2);
                    employee_removeEmployee(arrayEmployees,EMPLOYEES,auxiliarId);
               /* }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;

            case 4:

               // if(flag!=0){
      /*1*/         employee_orderByLastName(arrayEmployees,EMPLOYEES,0);
                    employee_orderBySector(arrayEmployees,EMPLOYEES,0);
                    employee_printEmployees(arrayEmployees,EMPLOYEES);
      /*2*/         averageSalary = employee_averageSalary(arrayEmployees,EMPLOYEES);
                    employee_aboveAverage(arrayEmployees,EMPLOYEES,averageSalary);
               /* }
                    else{

                        printf("\nDebe ingresar un empleado\n");
                }*/
                break;
        }
    }while(menu != 5);


    return 0;
}

