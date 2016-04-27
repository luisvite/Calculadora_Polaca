#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "Metodos.h"

//Declaracion del main
int main()
{
	char operacion[50],caracter;
	int tam,i;
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
        //Comenzamos a llenar
        for(i=0;i<=tam;i++)
        {
            if(operacion[i]==43 || operacion[i]==45)//+ o-
            {
                if(!ValidaVacioP(p))
                {

                }
                else
                {
                    Push(p,operacion[i]);
                }
            }
            else if(operacion[i]==42 || operacion[i]==47)//* o /
            {
                if(!ValidaVacioP(p))
                {

                }
                else
                {
                    Push(p,operacion[i]);
                }
            }
            else if(operacion[i]==94) // ^
            {
                if(!ValidaVacioP(p))
                {

                }
                else
                {
                    Push(p,operacion[i]);
                }
            }
            else if(operacion[i]==40 || operacion[i]==91)// ( o [
            {
                Push(p,operacion[i]);
            }
            else if(operacion[i]==41)// )
            {
                while(ElementoTope(p)!=40)
                {
                    caracter=Pop(p);
                    Insertar(c,caracter);
                }
                caracter=Pop(p);

            }
            else if(operacion[i]==93)//]
            {
                while(ElementoTope(p)!=91)
                {
                    caracter=Pop(p);
                    Insertar(c,caracter);
                }
                caracter=Pop(p);
            }
            else //significa que es un mumero o un punto
                Insertar(c,operacion[i]);
        }
	}
	else
	{
		printf("Error la operacion ingresada no es correcta...");
	}

	return 0;
}
