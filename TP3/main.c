#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  fscanf   set de cada uno d los campos
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).  recorrer la lista, tengo el dato y guardo en el txt fprintf
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario). fwrite
    10. Salir
*****************************************************/


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        getValidInt("\n\n1- Cargar(Modo Texto)\n2- Cargar(Modo Binario)\n3- Alta de Empleado\n4- Modificar Empleado\n5- Eliminar Empleado\n6- Listar Empleados\n7- Ordenar Empleados\n8- Guardar(Modo Texto)\n9- Guardar(Modo Binario)\n10- Salir\n","No valida\n",&option,1,10,1);
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados)){
                    printf("\nEmpleados Cargados ...\n");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados)){
                    printf("\nEmpleados Cargados ...\n");
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                    printf("\nEmpleado Cargado ...\n");
                break;
            case 4:
                if(ll_len(listaEmpleados)!=0){
                    controller_ListEmployeeId(listaEmpleados);
                    controller_editEmployee(listaEmpleados);
                }
                else{
                    printf("\nNo hay empleados en la lista");
                }
                break;
            case 5:
                if(ll_len(listaEmpleados)!=0){
                    controller_ListEmployeeId(listaEmpleados);
                    controller_removeEmployee(listaEmpleados);
                }
                else{
                    printf("\nNo hay empleados en la lista");
                }
                break;
            case 6:
                if(ll_len(listaEmpleados)!=0){
                    controller_ListEmployee(listaEmpleados);
                }
                else{
                    printf("\nNo hay empleados en la lista");
                }
                break;
            case 7:
                if(ll_len(listaEmpleados)>0){
                    controller_sortEmployee(listaEmpleados);
                    printf("\nLista de Empleados Ordenada");
                }
                else{
                    printf("\nError");
                }
                break;
            case 8:
                if(ll_len(listaEmpleados)>0){
                    controller_saveAsText("data.csv",listaEmpleados);
                    printf("\nArchivo generado...");
                }
                else{
                    printf("\nNo hay empleados en la lista");
                }
                break;
            case 9:
                if(ll_len(listaEmpleados)>0){
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    printf("\nArchivo generado...");
                }
                else{
                    printf("\nNo hay empleados en la lista");
                }
                break;


        }
    }while(option != 10);
    return 0;
}
