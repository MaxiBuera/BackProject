#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#define OCUPADO 0
#define LIBRE 1

static int proximoId();
/*static int generarId(void){
    static int id=-1;
    id++;
    return id;
}*/

int buscarLugarLibre(Cliente* arrayClientes,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayClientes[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_buscarPorId(Cliente* arrayClientes,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayClientes[i].isEmpty == OCUPADO && arrayClientes[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_inicializar(Cliente* arrayClientes, int limite)
{

    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayClientes[i].id = -1;
            strcpy(arrayClientes[i].nombre,"");
            strcpy(arrayClientes[i].apellido,"");
            strcpy(arrayClientes[i].cuit,"");
            arrayClientes[i].isEmpty = LIBRE;

        }
    }
    return retorno;
}

int cliente_alta(Cliente* arrayClientes,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char cuit[20];
    int id;
    int indice;
    int aux,i;

    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(arrayClientes,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Nombre: ","Error\n","Overflow", nombre,50,2))
            {
                if(!getValidString("Apellido: ","Error\n","Overflow", apellido,50,2))
                {

					for(i=0;i<2;i++){

						aux = getStringNumeros("Cuit: ",cuit);
						if(aux==0){

							printf("Error\n");
							continue;
						}

						retorno = 0;
                        strcpy(arrayClientes[indice].nombre,nombre);
                        strcpy(arrayClientes[indice].apellido,apellido);
                        strcpy(arrayClientes[indice].cuit,cuit);
                        arrayClientes[indice].id = id;
                        arrayClientes[indice].isEmpty = OCUPADO;
                        printf("Identificador Cliente: %d\n",arrayClientes[indice].id);
                        break;
					}

                }
            }
        }
    }
    return retorno;
}


int cliente_altaForzada(Cliente* arrayClientes, int limite, char nombre[],char apellido[],char cuit[])
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayClientes != NULL)
    {
        i = buscarLugarLibre(arrayClientes,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayClientes[i].nombre,nombre);
            strcpy(arrayClientes[i].apellido,apellido);
            strcpy(arrayClientes[i].cuit,cuit);
            //------------------------------
            //------------------------------
            arrayClientes[i].id = proximoId();
            arrayClientes[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}


int cliente_mostrar(Cliente* arrayClientes,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;

    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = 0;

        for(i=0;i<limite;i++)
        {
        	if(!arrayClientes[i].isEmpty)
            {

                if(flag==0){

                    printf("\n\tNombre\tApellido\tcuit\tid");
                    flag++;
                }

           		printf("\n\t%s\t%s\t\t%s\t%d",arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit,arrayClientes[i].id);
        	}
        }
    }
    return retorno;
}

int cliente_modificar(Cliente* arrayClientes, int limite,int index){

    int indice;
    int retorno = -1;
    char nombre[51];
    char apellido[51];
    char cuit[11];

    indice = cliente_buscarPorId(arrayClientes,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        if(getStringLetras("Ingrese nombre: ",nombre)){

            if(getStringLetras("Ingrese apellido: ",apellido)){

                if(!getStringLetras("Ingrese cuit: ",cuit)){

                    retorno = 0;
                    strcpy(arrayClientes[indice].nombre,nombre);
                    strcpy(arrayClientes[indice].apellido,apellido);
                    strcpy(arrayClientes[indice].cuit,cuit);
                }
            }
        }

    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int cliente_baja(Cliente* arrayClientes,int limite, int id)
{

    int retorno = -1;
    int indice;
    int baja, validaBaja;


    indice = cliente_buscarPorId(arrayClientes,limite,id);
    if(indice >= 0)
    {

        validaBaja = getValidInt("\n¿Confirma la baja del cliente ?[1-Si 2-No]","\nOpcion invalida\n",&baja,1,2,2);
        if(validaBaja == 0){

            arrayClientes[indice].isEmpty = LIBRE;

            printf("\nCliente eliminado");
            retorno = 0;
        }

    }

    return retorno;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
