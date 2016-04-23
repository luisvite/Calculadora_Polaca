#include<string.h>
#include<stdio.h>
#include<string.h>

//Declaracion de prototipos y estructuras  a utilizar
int ValidaCadena(char cadena[],int indice);

//Declaracion del main
int main()
{
    char operacion[50];
    
    printf("\t\tCALCULADORA POLACA\n");
    do
    {
        printf("Ingrese la expresion a ser evaluada: ");
        gets(operacion);    
    }while(ValidaCadena(operacion,50)==0);
    

    return 0;
}

//Declaracion de metodos

int ValidaCadena(char cadena[],int indice) //Si regresa 1 la cadenma es correcta. Regresa 0 es erronea.
{
    int i, acumulador=0;
    if(cadena[0]==47 || cadena[0]==42 || cadena[0]==43 || cadena[0]==45 || cadena[0]==94)
        return 0;
    else
        if(cadena[strlen(cadena)-1]==47 || cadena[strlen(cadena)-1]==42 || cadena[strlen(cadena)-1]==43 || cadena[strlen(cadena)-1]==45 || cadena[strlen(cadena)-1]==94)
            return 0;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>=47 && cadena[i]<=57 || cadena[i]>=40 && cadena[i]<=43 || cadena[i]==45 || cadena[i]==91 || cadena[i]==93 || cadena[i]==94)
            acumulador = acumulador +1;
    }
    if(acumulador == strlen(cadena))
        return 1;
    return 0;
}
