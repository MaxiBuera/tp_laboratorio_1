#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define OCCUPIED 0
#define FREE 1
#define EMPLOYEES 1000 // 1000 empleados

int main()
{
	setbuf(stdout, NULL);
    int menu;
    int index;
    int auxiliarId;
    int flag = 0;
    int flagAdd;
    float averageSalary;

    eEmployee arrayEmployees[EMPLOYEES];

    employee_initEmployees(arrayEmployees,EMPLOYEES);

    //Solo para testear
    /*employee_forceAdd(arrayEmployees,EMPLOYEES,"Pablo","Gimenez",20000,2);
    employee_forceAdd(arrayEmployees,EMPLOYEES,"Mariano","Alfonso",50000,1);
    employee_forceAdd(arrayEmployees,EMPLOYEES,"Marcelo","Gigliotti",50000,1);*/


    do{

        getValidInt("\n\n1.Alta Empleado\n2.Modificar Empleado\n3.Baja Empleado\n4.Informar\n5.Salir\n","\nNo valida\n",&menu,1,5,1);
        switch(menu)
        {

            case 1:

                index = employee_searchForFreePosition(arrayEmployees,EMPLOYEES);
                if(index >= 0){
                    flagAdd = employee_addEmployee(arrayEmployees,EMPLOYEES,index);
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
                    getValidInt("\tID a modificar: ","\nID No valido\n",&auxiliarId,0,EMPLOYEES,2);
                    employee_updateEmployee(arrayEmployees,EMPLOYEES,auxiliarId-1);
               }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 3:

                if(flag!=0){
                    employee_orderByLastName(arrayEmployees,EMPLOYEES,0);
                    employee_orderBySector(arrayEmployees,EMPLOYEES,0);
                    employee_showEmployeeUpdated(arrayEmployees,EMPLOYEES);
                    getValidInt("\nID a eliminar: ","\nID No valido\n",&auxiliarId,0,EMPLOYEES,2);
                    employee_removeEmployee(arrayEmployees,EMPLOYEES,auxiliarId-1);
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 4:

                if(flag!=0){
      /*1*/         employee_orderByLastName(arrayEmployees,EMPLOYEES,0);
                    employee_orderBySector(arrayEmployees,EMPLOYEES,0);
                    employee_printEmployees(arrayEmployees,EMPLOYEES);
      /*2*/         averageSalary = employee_averageSalary(arrayEmployees,EMPLOYEES);
                    employee_aboveAverage(arrayEmployees,EMPLOYEES,averageSalary);
                }
                    else{

                        printf("\nDebe ingresar un empleado\n");
                }
                break;
        }
    }while(menu != 5);


    return 0;
}

