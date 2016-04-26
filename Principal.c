#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "Metodos.h"

//Declaracion del main
int main()
{
	char operacion[50];
	int tam;
	Pila *p;
	Cola *c;

	printf("\t\tCALCULADORA POLACA\n");
	printf("Ingrese la expresion a ser evaluada en notacion infija: ");
	fflush(stdin);
	gets(operacion);

	tam=strlen(operacion);

	if(ValidaCadena(operacion,tam))
	{
	    //Creamos la Pila
        p=(Pila*)malloc(sizeof(Pila));
        p->arreglo=(char*)malloc(tam*sizeof(char));
        p->tope=-1;
        p->max=tam;
        //Creamos la cola
        c=(Cola*)malloc(sizeof(Cola));
        c->arreglo=(char*)malloc(tam*sizeof(char));
        c->header=-1;
        c->tail=-1;
        c->max=tam;


	}
	else
	{
		printf("Error la operacion ingresada no es correcta...");
	}

	return 0;
}
