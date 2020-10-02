#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

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
int employee_initEmployees(eEmployee* arrayEmployees, int limite);

 /**
 * \brief Carga el array de cliente
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int employee_addEmployees(eEmployee* arrayEmployees, int limite, int index);

/**
 * \brief Modifica el array de un empleado
 * \param array de Empleados
 * \param limite de array de Empleados
 * \param id Empleado a buscar
 * \return 0 si la entrada es correcta
 */
int employee_modificacion(eEmployee* arrayEmployees, int limit, int index);

int employee_mostrarModificacion(eEmployee* arrayEmployees,int limit);

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
int employee_buscarLugarLibre(eEmployee* arrayEmployees,int limit);

/**
 * \brief Busca id dentro del array
 * \param array de Empleados
 * \param limite de array de Empleados
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int employee_buscarPorId(eEmployee* arrayEmployees,int limit, int id);

/**
 * \brief Ordena el array de empleados [Por Apellido - Por Sector]
 * \param array de Empleados
 * \param limite de array de Empleados
  * \param orden criterio a ordenar
 * \return 0 si la entrada es correcta
 */
int employee_ordenarXapellido(eEmployee* arrayEmployees,int limite, int orden);
int employee_ordenarXsector(eEmployee* arrayEmployees,int limite, int orden);

float employee_promedioSueldos(eEmployee* arrayEmployees,int limite);

int employee_superiorAlPromedio(eEmployee* arrayEmployees,int limite, float promedioSueldos);

/**
 * \brief Alta de una empleado sin usar ciclos
 * \param array de Empleados
 * \param limite de array de Empleados
 * \param name del empleado
 * \param lastname del empleado
 * \param salary salario del empleado
 * \param sector sector del empleado
 * \return 0 si la entrada es correcta
 */
int employee_altaForzada(eEmployee* arrayEmployees,int limite,char* name,char* lastname, float salary,int sector);

/**
 * \brief Muestra el array de Empleados
 * \param array de Empleados
 * \param limite de array de Empleados
 * \return 0 si la entrada es correcta
 */
int employee_mostrar(eEmployee* arrayEmployees,int limite);

