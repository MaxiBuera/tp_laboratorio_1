#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "empleado.h"
#define SECTOR 10
#define SALARIOMIN 0
#define SALARIOMAX 100000
#define OCUPADO 0
#define LIBRE 1

static int proximoId();

void empleado_normalizarCadena(char cadena[]){

    int j,i;
    i = strlen(cadena);

    for(j=0;j<i;j++){

        if(j==0){

            cadena[j] = toupper(cadena[j]);
        }
        else{

            cadena[j] = tolower(cadena[j]);
        }
    }
}

int empleado_inicializar(eEmployee* arrayEmpleados, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayEmpleados[i].id = -1;
            strcpy(arrayEmpleados[i].name,"");
            strcpy(arrayEmpleados[i].lastname,"");
            arrayEmpleados[i].salary = 0;
            arrayEmpleados[i].sector = -1;
            arrayEmpleados[i].isEmpty = LIBRE;

        }
    }
    return retorno;
}

int empleado_alta(eEmployee* arrayEmpleados, int limite, int index){

    int retorno = -1;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;
    int id;

    if(limite > 0 && arrayEmpleados != NULL){

        retorno = -2;
        id = proximoId();

        if(getStringLetras("Ingrese nombre: ",nameAux)){

            if(getStringLetras("Ingrese apellido: ",lastnameAux)){

                if(!getValidFloat("Ingrese salario: ","\nError\n",&salaryAux,SALARIOMIN,SALARIOMAX,2)){

                    if(!getValidInt("Ingrese sector: ","\nError\n",&sectorAux,0,SECTOR,2)){

                        empleado_normalizarCadena(nameAux);
                        strcpy(arrayEmpleados[index].name,nameAux);

                        empleado_normalizarCadena(lastnameAux);
                        strcpy(arrayEmpleados[index].lastname,lastnameAux);

                        arrayEmpleados[index].salary = salaryAux;
                        arrayEmpleados[index].sector = sectorAux;
                        arrayEmpleados[index].isEmpty = OCUPADO;
                        arrayEmpleados[index].id = id;
                        retorno = 0;
                    }
                }
            }
        }
    }

    if(retorno != 0){

        printf("\nError\n");
    }

    return retorno;

}

int empleado_buscarLugarLibre(eEmployee* arrayEmpleados,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayEmpleados[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int empleado_altaForzada(eEmployee* arrayEmpleados,int limite,char* name,char* lastname, float salary,int sector)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayEmpleados != NULL)
    {
        i = empleado_buscarLugarLibre(arrayEmpleados,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayEmpleados[i].name,name);
            strcpy(arrayEmpleados[i].lastname,lastname);
            arrayEmpleados[i].salary = salary;
            arrayEmpleados[i].sector = sector;
            //------------------------------
            //------------------------------
            arrayEmpleados[i].id = proximoId();
            arrayEmpleados[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int empleado_mostrar(eEmployee* arrayEmpleados,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = 0;
        printf("\n\tNombre\t\tApellido\tID\tSector\tSalario");
        for(i=0;i<limite;i++)
        {
        	if(!arrayEmpleados[i].isEmpty)
            {

           		printf("\n\t%s\t\t%s\t\t%d\t%d\t%.2f",arrayEmpleados[i].name,arrayEmpleados[i].lastname,arrayEmpleados[i].id,arrayEmpleados[i].sector,arrayEmpleados[i].salary);
           	}
        }
    }
    return retorno;
}

int empleado_buscarPorId(eEmployee* arrayEmpleados,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayEmpleados[i].isEmpty == OCUPADO && arrayEmpleados[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int empleado_mostrarModificacion(eEmployee* arrayEmpleados,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = 0;
        printf("\n\tNombre\t\tApellido\tID");
        for(i=0;i<limite;i++)
        {
        	if(!arrayEmpleados[i].isEmpty)
            {

           		printf("\n\t%s\t\t%s\t\t%d",arrayEmpleados[i].name,arrayEmpleados[i].lastname,arrayEmpleados[i].id);
        	}
        }
    }
    printf("\n\n");
    return retorno;
}

int empleado_modificacion(eEmployee* arrayEmpleados, int limite,int index){

    int indice;
    int retorno = -1;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;


    indice = empleado_buscarPorId(arrayEmpleados,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        if(getStringLetras("Ingrese nombre: ",nameAux)){

            if(getStringLetras("Ingrese nombre: ",lastnameAux)){

                if(!getValidFloat("Ingrese salario: ","\nError",&salaryAux,SALARIOMIN,SALARIOMAX,2)){

                    if(!getValidInt("Ingrese sector: ","\nError",&sectorAux,0,SECTOR,2)){

                        strcpy(arrayEmpleados[index].name,nameAux);
                        strcpy(arrayEmpleados[index].lastname,lastnameAux);
                        arrayEmpleados[index].salary = salaryAux;
                        arrayEmpleados[index].salary = sectorAux;
                        arrayEmpleados[index].isEmpty = OCUPADO;
                        retorno = 0;
                    }
                }
            }
    }
    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int empleado_baja(eEmployee* arrayEmpleados, int limite,int index){

    int retorno = -1;
    int indice;
    indice = empleado_buscarPorId(arrayEmpleados,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        arrayEmpleados[indice].isEmpty = LIBRE;
    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int empleado_ordenarXapellido(eEmployee* arrayEmpleados,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayEmpleados[i].isEmpty == OCUPADO && arrayEmpleados[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arrayEmpleados[i].lastname,arrayEmpleados[i+1].lastname) > 0 && !orden) || (strcmp(arrayEmpleados[i].lastname,arrayEmpleados[i+1].lastname) < 0 && orden)) //<------------
                        {
                            auxiliar = arrayEmpleados[i];
                            arrayEmpleados[i] = arrayEmpleados[i+1];
                            arrayEmpleados[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

int empleado_ordenarXsector(eEmployee* arrayEmpleados,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eEmployee auxiliar;

    if(limite > 0 && arrayEmpleados != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayEmpleados[i].isEmpty == OCUPADO && arrayEmpleados[i+1].isEmpty == OCUPADO )
                    {
                        if((arrayEmpleados[i].sector > arrayEmpleados[i+1].sector && !orden) || (arrayEmpleados[i].sector < arrayEmpleados[i+1].sector && orden)) //<------------
                        {
                            auxiliar = arrayEmpleados[i];
                            arrayEmpleados[i] = arrayEmpleados[i+1];
                            arrayEmpleados[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

float totalSueldos(eEmployee* arrayEmpleados,int limite){

    int i;
    float total = 0;

    if(limite > 0 && arrayEmpleados != NULL){

        for(i=0;i<limite;i++){

            total = total + arrayEmpleados[i].salary;
        }
    }

    return total;
}

int empleadosActuales(eEmployee* arrayEmpleados,int limite){

    int i;
    int cantidadEmpleados = 0;

    if(limite > 0 && arrayEmpleados != NULL){

        for(i=0;i<limite;i++){

            if(arrayEmpleados[i].isEmpty == 0){

                cantidadEmpleados++;
            }
        }
    }

    return cantidadEmpleados;
}

float empleado_promedioSueldos(eEmployee* arrayEmpleados,int limite){

    float total,promedioSueldos;
    int cantidadEmpleados;

    if(limite > 0 && arrayEmpleados != NULL){

        total = totalSueldos(arrayEmpleados,limite);
        cantidadEmpleados = empleadosActuales(arrayEmpleados,limite);

        promedioSueldos = total / cantidadEmpleados;

        printf("\ntotal sueldos: %.2f",total);
        printf("\nSueldo Promedio: %.2f",promedioSueldos);
    }

    return promedioSueldos;
}

int empleado_superiorAlPromedio(eEmployee* arrayEmpleados,int limite, float promedioSueldos){

    int retorno = -1;
    int i;
    int cantidadEmpleadosMayorAlPromedio = 0;

    if(limite > 0 && arrayEmpleados != NULL){

        retorno = 0;

        for(i=0;i<limite;i++){

            if(arrayEmpleados[i].salary > promedioSueldos){

                cantidadEmpleadosMayorAlPromedio++;
            }
        }
    }

    printf("\n\nCantidad de empleados cuyos salarios superan el promedio: %d empleados",cantidadEmpleadosMayorAlPromedio);

    return retorno;
}



static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
