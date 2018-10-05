#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct{
    int idCliente;
    int idVenta;
    int cantidadAfiches;
    char imagenAfiche[51];
    int zonaAfiche;
    int estado;
    int isEmpty;
}Venta;

#endif // VENTA_H_INCLUDED

int venta_buscarPorId(Venta* arrayVentas,int limite, int id);

int venta_inicializar(Venta* arrayVentas, int limite);

int venta_alta(Cliente* arrayClientes, Venta* arrayVentas, int limiteVentas, int idCliente, int limiteClientes);

int venta_mostrar(Venta* arrayVentas,int limite);

int venta_modificar(Cliente* arrayClientes, Venta* arrayVentas, int limite,int limiteClientes,int idCliente);

