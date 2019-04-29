#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define OCUPADO 0
#define LIBRE 1
#define EMPLEADOS 5

//1º inicializar Lista
//2º Buscar Lugar Libre
//3º Gernerar Id

int main()
{

    int menu;
    int index;
    int auxiliarId;
    //char cuit[75];

    eEmployee arrayEmpleados[EMPLEADOS];

    empleado_inicializar(arrayEmpleados,EMPLEADOS);

    empleado_altaForzada(arrayEmpleados,EMPLEADOS,"Pablo","Gimenez",20000,1);
    empleado_altaForzada(arrayEmpleados,EMPLEADOS,"Mariano","Alfonso",30000,1);



    do{

        getValidInt("\n\n1.Alta Empleado\n2.Modificar Empleado\n3.Baja Empleado\n4.Mostrar Empleados\n5.Informes\n6.Salir\n","\nNo valida\n",&menu,1,4,1);
        switch(menu)
        {

            case 1:

                index = empleado_buscarLugarLibre(arrayEmpleados,EMPLEADOS);
                if(index >= 0){

                    empleado_alta(arrayEmpleados,EMPLEADOS,index);
                    break;
                }

            case 2:

                getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLEADOS,2);
                empleado_modificacion(arrayEmpleados,EMPLEADOS,auxiliarId);
                break;

            case 3:

                getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,EMPLEADOS,2);
                empleado_baja(arrayEmpleados,EMPLEADOS,auxiliarId);
                break;

            case 4:
//SACAR
                empleado_mostrar(arrayEmpleados,EMPLEADOS);
                break;

            case 5:
/*
                getStringNumeros("Ingrese Cuit: ",cuit);
*/
                break;

            case 10:
/*
                pantalla_mostrar(arrayPantallas,Pantallas);
                printf("\n");
                publicidad_mostrar(arrayPublicidades,Publicidades);
               */ break;
        }
    }while(menu != 10);


    return 0;
}

/*
int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Cliente auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}
*/

