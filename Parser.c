#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Participante.h"
#include "Parser.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int encabezado;
	char* numeroConcursante=NULL;
    char* anio=NULL;
    char* nombre=NULL;
    char* dni=NULL;
    char* fechaPresentacion=NULL;
    char* temaPresentacion=NULL;
    char* puntajePrimeraRonda=NULL;

    numeroConcursante=(char*)malloc(sizeof(char)*4);
    anio=(char*)malloc(sizeof(char)*4);
    nombre=(char*)malloc(sizeof(char)*30);
    dni=(char*)malloc(sizeof(char)*8);
    fechaPresentacion=(char*)malloc(sizeof(char)*10);
    temaPresentacion=(char*)malloc(sizeof(char)*50);
    puntajePrimeraRonda=(char*)malloc(sizeof(char)*4);

	Employee* aEmployee;

	encabezado = 0;
	while(!feof(pFile))
	{
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numeroConcursante,anio,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
		if(encabezado != 0)
		{
			aEmployee = employee_newParametros(numeroConcursante,anio,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
			aEmployee->puntajeSegundaRonda = 0;
			aEmployee->promedioPuntaje = 0;
			ll_add(pArrayListEmployee, aEmployee);
        }
        encabezado++;
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* aEmployee;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            aEmployee = employee_new();
            fread(aEmployee,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,aEmployee);
        }
        retorno = 0;
    }
    return retorno;
}


int parser_ConcursanteFromText(FILE* pFile, LinkedList* pArrayListConcursantes)
{
    Employee* aux_concursante=NULL;
    int ret=1;
    int counter=0;
    int i=0;
    char* id=NULL;
    char* anioNacimiento=NULL;
    char* nombre=NULL;
    char* dni=NULL;
    char* fechaPresentacion=NULL;
    char* temaPresentacion=NULL;
    char* primeraRonda=NULL;
    char* segundaRonda=NULL;
    char* promedioPuntaje=NULL;
    id=(char*)malloc(sizeof(char)*4);
    anioNacimiento=(char*)malloc(sizeof(char)*4);
    nombre=(char*)malloc(sizeof(char)*30);
    dni=(char*)malloc(sizeof(char)*8);
    fechaPresentacion=(char*)malloc(sizeof(char)*10);
    temaPresentacion=(char*)malloc(sizeof(char)*50);
    primeraRonda=(char*)malloc(sizeof(char)*4);

if(pArrayListConcursantes!=NULL)
    {
    while(!feof(pFile))
        {
        printf("LEYENDO\n");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,primeraRonda);
        counter++;
        }
    if(counter>0)
        {
        rewind(pFile);
        for(i=0;i<counter;i++)
            {
            printf("LEVANTANDO\n");
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,primeraRonda);
            printf("Primero\n");
            aux_concursante=employee_newParametros(id,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,primeraRonda);
            printf("AUX_CONCURSANTE: %p\n",aux_concursante);
            if(aux_concursante!=NULL)
                {
                printf("Concursante okay\n");
                ll_add(pArrayListConcursantes,aux_concursante);
                }
            }
        }
    }
return ret;
}
