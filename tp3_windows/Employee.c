#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

int proximoId();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this = employee_new();

    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    strcpy(nombre,nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    employee_setId(this,proximoId());
    employee_setNombre(this,nombre);
    employee_setHorasTrabajadas(this,horasTrabajadas);
    employee_setSueldo(this,sueldo);

    return this;
}

Employee* employee_newParametros2(char* nombre,int horasTrabajadas,int sueldo){

    Employee* this;
    this = employee_new();

    if(     !employee_setId(this, proximoId())
       &&   !employee_setNombre(this, nombre)
       &&   !employee_setHorasTrabajadas(this, horasTrabajadas)
       &&   !employee_setSueldo(this,sueldo))
    {
         return this;
    }
    employee_delete(this);
    return NULL;
}

Employee* employee_newParametros3(int id,char* nombre,int horasTrabajadas,int sueldo){

    Employee* this;
    this = employee_new();

    if(     !employee_setId(this, id)
       &&   !employee_setNombre(this, nombre)
       &&   !employee_setHorasTrabajadas(this, horasTrabajadas)
       &&   !employee_setSueldo(this,sueldo))
    {
         return this;
    }
    employee_delete(this);
    return NULL;
}

Employee* employee_newParametros4(int id,char* nombre,int horasTrabajadas,int sueldo){

    Employee* this;
    this = employee_new();

    if(     !employee_setId(this, proximoId())
       &&   !employee_setNombre(this, nombre)
       &&   !employee_setHorasTrabajadas(this, horasTrabajadas)
       &&   !employee_setSueldo(this,sueldo))
    {
         return this;
    }
    employee_delete(this);
    return NULL;
}

Employee* employee_new()
{
    return malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
    free(this);
}


int  employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {

        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
         retorno = 0;
    }
    return retorno;
}


char  employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {

        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


char employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;

}

int  employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas;
         retorno = 0;
    }
    return retorno;
}

int  employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {

        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;
         retorno = 0;
    }
    return retorno;
}

int proximoId()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}
