#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define OCUPADO 0
#define LIBRE 1
#define EMPLEADOS 5

int main()
{

    int menu;
    int index;
    int auxiliarId;
    int flag = 0;
    int flagAlta;
    float promedioSueldos;

    eEmployee arrayEmpleados[EMPLEADOS];

    empleado_inicializar(arrayEmpleados,EMPLEADOS);

    //empleado_altaForzada(arrayEmpleados,EMPLEADOS,"Pablo","Gimenez",20000,2);
    //empleado_altaForzada(arrayEmpleados,EMPLEADOS,"Mariano","Alfonso",30000,1);



    do{

        getValidInt("\n\n1.Alta Empleado\n2.Modificar Empleado\n3.Baja Empleado\n4.Informar\n5.Salir\n","\nNo valida\n",&menu,1,5,1);
        switch(menu)
        {

            case 1:

                index = empleado_buscarLugarLibre(arrayEmpleados,EMPLEADOS);
                if(index >= 0){

                    flagAlta = empleado_alta(arrayEmpleados,EMPLEADOS,index);
                    if(flagAlta == 0)
                        flag = 1;
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 2:

                if(flag!=0){
                    empleado_mostrarModificacion(arrayEmpleados,EMPLEADOS);
                    getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLEADOS,2);
                    empleado_modificacion(arrayEmpleados,EMPLEADOS,auxiliarId);
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 3:

                if(flag!=0){

                    getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLEADOS,2);
                    empleado_baja(arrayEmpleados,EMPLEADOS,auxiliarId);
                }
                else{

                    printf("\nDebe ingresar un empleado\n");
                }
                break;

            case 4:

                if(flag!=0){
      /*1*/         empleado_ordenarXapellido(arrayEmpleados,EMPLEADOS,0);
                    empleado_ordenarXsector(arrayEmpleados,EMPLEADOS,0);
                    empleado_mostrar(arrayEmpleados,EMPLEADOS);
      /*2*/         promedioSueldos = empleado_promedioSueldos(arrayEmpleados,EMPLEADOS);
                    empleado_superiorAlPromedio(arrayEmpleados,EMPLEADOS,promedioSueldos);
                }
                    else{

                        printf("\nDebe ingresar un empleado\n");
                }
                break;
        }
    }while(menu != 5);


    return 0;
}

