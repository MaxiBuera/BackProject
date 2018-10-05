#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "venta.h"
#define qtyClientes 5
#define qtyVentas 5
#define OCUPADO 0
#define LIBRE 1
#define A_COBRAR 0
#define COBRADA 1
#define CABA
#define ZONA_SUR
#define ZONA_OESTE

static int proximoId();
/*static int generarId(void){
    static int id=-1;
    id++;
    return id;
}*/

int venta_buscarLugarLibre(Venta* arrayVentas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVentas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayVentas[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int venta_buscarPorId(Venta* arrayVentas,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVentas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayVentas[i].isEmpty == OCUPADO && arrayVentas[i].idVenta == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int venta_inicializar(Venta* arrayVentas, int limite)
{

    int retorno = -1;
    int i;
    if(limite > 0 && arrayVentas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayVentas[i].idCliente = -1;
            arrayVentas[i].cantidadAfiches = 0;
            strcpy(arrayVentas[i].imagenAfiche,"");
            arrayVentas[i].zonaAfiche = -1;
            arrayVentas[i].idVenta = -1;
            arrayVentas[i].isEmpty = LIBRE;

        }
    }
    return retorno;
}

int venta_buscarIdCliente(Cliente* arrayClientes, int idCliente ,int limiteClientes){

    int retorno = -1;
    int i;

    for(i=0;i<limiteClientes;i++){

        if(arrayClientes[i].id == idCliente){

            retorno = 0;
            break;
        }
    }

    return retorno;

}


int venta_alta(Cliente* arrayClientes, Venta* arrayVentas, int limiteVentas, int idCliente, int limiteClientes)
{
    int retorno = -1;

    int cantidadAfiches;
    char imagenAfiche[51];
    int zonaAfiche;
    int idVenta;
    int indice;
    int auxIdCliente;



    if(limiteVentas > 0 && arrayVentas != NULL)
    {
        retorno = -2;

        auxIdCliente = venta_buscarIdCliente(arrayClientes,idCliente,limiteClientes);

        if(auxIdCliente == 0){

            indice = venta_buscarLugarLibre(arrayVentas,limiteVentas);
            if(indice >= 0)
            {

                retorno = -3;
                idVenta = proximoId();
                if(!getValidInt("Cantidad de Afiches: ","\nCantidad invalida\n",&cantidadAfiches,0,200,2))
                {
                    if(!getValidAlfaNumerico("Nombre Afiche: ","Error\n","Overflow",imagenAfiche,75,2))
                    {

                        if(!getValidInt("Zona [1-CABA 2-ZONA SUR 3-ZONA OESTE]: ","\nOpcion invalida\n",&zonaAfiche,1,3,2))
                        {

                            retorno = 0;
                            arrayVentas[indice].cantidadAfiches = cantidadAfiches;
                            strcpy(arrayVentas[indice].imagenAfiche,imagenAfiche);
                            arrayVentas[indice].zonaAfiche = zonaAfiche;
                            arrayVentas[indice].idVenta = idVenta;
                            arrayVentas[indice].isEmpty = OCUPADO;
                            arrayVentas[indice].estado = A_COBRAR;
                            .idCliente =
                            printf("Identificador Venta: %d\n",arrayVentas[indice].idVenta);
                        }

                    }
                }
            }
        }
        else{

            printf("\nID No Encontrado");
        }


    }
    return retorno;
}



/*
int venta_altaForzada(Venta* arrayVentas, int limite, char nombre[],char apellido[],char cuit[])
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayVentas != NULL)
    {
        i = buscarLugarLibre(arrayVentas,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayVentas[i].nombre,nombre);
            strcpy(arrayVentas[i].apellido,apellido);
            strcpy(arrayVentas[i].cuit,cuit);
            //------------------------------
            //------------------------------
            arrayVentas[i].id = proximoId();
            arrayVentas[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}
*/

int venta_mostrar(Venta* arrayVentas,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;


        if(limite > 0 && arrayVentas != NULL)
        {
            retorno = 0;

            for(i=0;i<limite;i++)
            {
                if(!arrayVentas[i].isEmpty)
                {
                    if(flag==0){
                        printf("\n\tID Cliente\tCantidad de Afiches\tImagen Afiche\tZona Afiche\tID Venta");
                        flag++;
                    }
                    printf("\n\t%d\t%d\t%s\t%d\t%d",arrayVentas[i].idCliente,arrayVentas[i].cantidadAfiches,arrayVentas[i].imagenAfiche,arrayVentas[i].zonaAfiche,arrayVentas[i].idVenta);
                }
            }
        }



    return retorno;
}

int venta_modificar(Cliente* arrayClientes, Venta* arrayVentas, int limite,int limiteClientes,int idCliente){

    int indice;
    int retorno = -1;
    int auxIdCliente;
    int cantidadAfiches;
    int zonaAfiche;

    auxIdCliente = venta_buscarIdCliente(arrayClientes,idCliente,limiteClientes);

        if(auxIdCliente == 0){


            indice = venta_buscarLugarLibre(arrayVentas,limite);
            if(indice >= 0)
            {
                retorno = 0;
                if(!getValidInt("Cantidad de Afiches: ","\nCantidad invalida\n",&cantidadAfiches,0,200,2))
                {
                    if(!getValidInt("Zona [1-CABA 2-ZONA SUR 3-ZONA OESTE]: ","\nOpcion invalida\n",&zonaAfiche,1,3,2))
                    {

                        arrayVentas[indice].cantidadAfiches = cantidadAfiches;
                        arrayVentas[indice].zonaAfiche = zonaAfiche;
                    }
                }

            }
            else{

                printf("\nID no encontrado");
            }
                }


    return retorno;
}

int venta_cobrar(Venta* arrayVentas, int limite){

    int retorno = -1;



    return retorno;
}

/*
int cliente_baja(Cliente* arrayClientes,int limite, int id)
{

    int retorno = -1;
    int indice;
    int baja, validaBaja;


    indice = buscarPorId(arrayClientes,limite,id);
    if(indice >= 0)
    {

        validaBaja = getValidInt("\n¿Confirma la baja del cliente ?[1-Si 2-No]","\nOpcion invalida\n",&baja,1,2,2);
        if(validaBaja == 0){

            arrayClientes[indice].isEmpty = LIBRE;

            printf("\nCliente eliminado");
        }

    }

    return retorno;

}
*/
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
