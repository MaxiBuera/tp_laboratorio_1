#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

#endif // EMPLEADO_H_INCLUDED

/** \brief  Para indicar que todas las posiciones estan vacias,
 *          esta funcion coloca el flag (isEmpty) en True en
 *          todas las posiciones del array
 *
 * \param   array de Empleados
 * \param   limite del array de Empleados
 *
 * \return 0 si la entrada es correcta, sino -1
 *
 */
int employee_initEmployees(eEmployee* arrayEmployees, int limit);

 /**
 * \brief Carga el array de cliente
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int employee_addEmployees(eEmployee* arrayEmployees, int limit, int index);

/**
 * \brief Modifica el array de un empleado
 * \param array de Empleados
 * \param limite de array de Empleados
 * \param id Empleado a buscar
 * \return 0 si la entrada es correcta
 */
int employee_updateEmployees(eEmployee* arrayEmployees, int limit, int index);

int employee_showEmployeeUpdated(eEmployee* arrayEmployees,int limit);

/**
 * \brief Baja de un Empleado
 * \param array de Empleado
 * \param limite de array de Empleados
 * \param id a buscar
 * \return -1 o -2 si falla
 */
int employee_removeEmployee(eEmployee* arrayEmployees, int limit, int index);

/**
 * \brief Busca una posicion vacia del array
 * \param array de Empleado
 * \param limite de array de Empleados
 * \return -1 o -2 si falla
 */
int employee_searchForFreePosition(eEmployee* arrayEmployees,int limit);

/**
 * \brief Busca id dentro del array
 * \param array de Empleados
 * \param limite de array de Empleados
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int employee_findEmployeeById(eEmployee* arrayEmployees,int limit, int id);

/**
 * \brief Ordena el array de empleados [Por Apellido: "employee_orderByLastName" - Por Sector: "employee_orderBySector"]
 * \param array de Empleados
 * \param limite de array de Empleados
  * \param orden criterio a ordenar
 * \return 0 si la entrada es correcta
 */
int employee_orderByLastName(eEmployee* arrayEmployees,int limit, int order);
int employee_orderBySector(eEmployee* arrayEmployees,int limit, int order);

float employee_averageSalary(eEmployee* arrayEmployees,int limit);

int employee_aboveAverage(eEmployee* arrayEmployees,int limit, float averageSalary);

/**
 * \brief Alta de una empleado sin usar ciclos (solo para pruebas)
 * \param array de Empleados
 * \param limite de array de Empleados
 * \param name del empleado
 * \param lastname del empleado
 * \param salary salario del empleado
 * \param sector sector del empleado
 * \return 0 si la entrada es correcta
 */
int employee_forceAdd(eEmployee* arrayEmployees,int limite,char* name,char* lastname, float salary,int sector);

/**
 * \brief Muestra el array de Empleados de forma encolumnada.
 * \param array de Empleados
 * \param limite de array de Empleados
 * \return 0 si la entrada es correcta
 */
int employee_printEmployees(eEmployee* arrayEmployees,int limit);

