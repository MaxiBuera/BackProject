#include <stdio.h>
#include <stdlib.h>

/*int mostrar(int *x, int y){

    *x = y;
    printf("%d %d", *x,y);
    return 0;
}*/
int factorial(int );
int factorial2(int );

int main()
{
    /*int x=1;
    int y=2;
    mostrar(&x,y);*/


    int valor,result;
    printf("\nIngrese numero:");
    scanf("%d",&valor);
    result=factorial2(valor);
    printf("\nEl factorial de %d es %d",valor,result);


    return 0;
}

int factorial(int n)
{
    int resp;
    if(n==1)
    return 1;
    resp=n* factorial(n-1);
    return (resp);
}

int factorial2(int n){

    int resp=1;
    int i;

    /*for(i=n;i>0;i--){

        resp = resp * i ;
    }*/

    for(i=1;i<n+1;i++){

        //printf("%d %d\n",resp,i);
        resp = resp * i;
    }

    return resp;
}

