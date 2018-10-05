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

int main()
{
    Cliente arrayClientes[qtyClientes];
    cliente_inicializar(arrayClientes,qtyClientes);
    Venta arrayVentas[qtyVentas];
    venta_inicializar(arrayVentas,qtyVentas);

    cliente_altaForzada(arrayClientes, qtyClientes, "Pedro","Gimenez","14789123");
    cliente_altaForzada(arrayClientes, qtyClientes, "Belen","Jimenez","17891456");

    int opcion;
    int auxiliarId;
    int validaMod;


    do
    {
    	getValidInt("\n\n1- Alta cliente\n2- Modificar Empleado\n3- Baja Cliente\n4- Vender Afiche\n5- Editar Venta\n6- Salir\n","No valida\n",&opcion,1,7,1);


        switch(opcion)
        {
            case 1:
            	cliente_alta(arrayClientes,qtyClientes);
                break;
            case 2:
                validaMod = getValidInt("ID: ","\nID invalido\n",&auxiliarId,0,qtyClientes,2);
                if(validaMod == 0){
                	cliente_modificar(arrayClientes,qtyClientes,auxiliarId);
				}
                break;
            case 3:
                validaMod = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,qtyClientes,2);
                if(validaMod == 0){
                	cliente_baja(arrayClientes,qtyClientes,auxiliarId);
				}
                break;
            case 4:
                validaMod = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,qtyClientes,2);
                if(validaMod == 0){
                	venta_alta(arrayClientes,arrayVentas,qtyVentas,auxiliarId,qtyClientes);
				}
                break;
            case 5:
                //cliente_mostrar(arrayClientes,qtyClientes);
                validaMod = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,qtyClientes,2);
                if(validaMod == 0){

                    venta_mostrar(arrayVentas,qtyVentas);
                    venta_modificar(arrayClientes,arrayVentas,qtyVentas,qtyClientes,auxiliarId);
                }
                break;
            case 6:
                venta_mostrar(arrayVentas,qtyVentas);

                break;
            case 7:

                break;
        }
    }while(opcion!=7);

   return 0;
}
