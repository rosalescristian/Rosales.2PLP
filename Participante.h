#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED

typedef struct
{
    int id;
    int anioNacimiento;
    char nombre[30];
    char dni[8];
    char fechaPresentacion[10];
    char temaPresentacion[50];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedioPuntaje;

}Employee;


#endif // PARTICIPANTE_H_INCLUDED

Employee* employee_new();
//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametros(char* numeroConcursante,char* anio, char* nombre,char* dni,char* fechaPresentacion,char* temaPresentacion,char* puntajePrimeraRonda);
void employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int *id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadasStr);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int isValidNombre(Employee* this, char* nombreStr);
int isValidId(Employee* this, char* id);
int isValidHsTrabajadas(Employee* this, char* horasTrabajadasStr);
int isValidSueldo(Employee* this, char* sueldo);

int getIdStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getNombreStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getHsTrabajadasStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getSueldoStr(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);

int employee_sortByName(void* dato1,void* dato2);
int findPushEmployeeByName(LinkedList* this);
int controller_pushEmployee(LinkedList* pArrayListEmployee,int auxId, Employee* replaceEmployee);
int findDeleteEmployeeByName(LinkedList* this);

int employee_setDni(Employee* this,char* dni);

int employee_setAnio(Employee* this,char* anio);

int employee_setFechaPresentacion(Employee* this,char* fechaPresentacion);

int employee_setTemaPresentacion(Employee* this,char* temaPresentacion);

int employee_setPuntaje(Employee* this,char* puntajePrimeraRonda);

int employee_getInt(Employee* this,int* number);
int employee_setInt(Employee* this,char* number);

int employee_getStr(Employee* this,char* cadena);
int employee_setStr(Employee* this,char* cadena);

int employee_getDni(Employee* this,char* dni);
int employee_getAnio(Employee* this,int* anio);
int employee_getFechaPresentacion(Employee* this,char* fecha);
int employee_getTemaPresentacion(Employee* this,char* tema);
int employee_getPuntajePrimeraRonda(Employee* this,int *number);

int employee_juradoCalculaPuntaje(void* this);
int employee_calculoSegundaRonda(Employee* this);
int employee_setSegundaRonda(Employee* this,int puntajeSegundaRonda);
int employee_calculoPromedioPuntaje(Employee* this);
int employee_getPuntajeSegundaRonda(Employee* this,int *number);
int employee_setPromedio(Employee* this,float promedio);
int employee_getPromedioPuntaje(Employee* this,float* promedio);
int employee_countMinusTen(void* this);
