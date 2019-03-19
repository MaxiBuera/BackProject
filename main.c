#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int i;

    /*for(i=0;i<11;i++){

        printf("%d\n",i);    <=== FOR
    }
    --------------------------------------
    */

    /*i=0;
    while(i<11){

        printf("%d\n",i);   <=== WHILE
        i++;
    }
    ---------------------------------------


    do{

        printf("%d\n",i);
        i++;                 <=== DO-WHILE
    }while(i<11);
    ---------------------------------------
    */

    char hora;

    printf("Ingrese una Hora: ");
    scanf("%d",&hora);

    switch(hora){

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if(hora<6)
            printf("Dormir");
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        if(hora>6)
            printf("Levantate");
        break;
    }

    return 0;
}
