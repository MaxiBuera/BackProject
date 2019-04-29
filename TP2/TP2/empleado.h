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

int empleado_inicializar(eEmployee* arrayEmpleados, int limite);
int empleado_alta(eEmployee* arrayEmpleados, int limite, int index);
int empleado_modificacion(eEmployee* arrayEmpleados, int limite, int index);
int empleado_baja(eEmployee* arrayEmpleados, int limite, int index);

int empleado_buscarLugarLibre(eEmployee* arrayEmpleados,int limite);
int empleado_buscarPorId(eEmployee* arrayEmpleados,int limite, int id);

int empleado_altaForzada(eEmployee* arrayEmpleados,int limite,char* name,char* lastname, float salary,int sector);
int empleado_mostrar(eEmployee* arrayEmpleados,int limite);

