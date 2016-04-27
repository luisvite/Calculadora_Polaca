#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "Metodos.h"

//Declaracion del main
int main()
{
	char operacion[50],caracter;
	int tam,i,j;
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
                    if(ElementoTope(p)==94)
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        if(!ValidaVacioP(p))
                        {
                            if(ElementoTope(p)==42 ||ElementoTope(p)==47)
                            {
                                caracter=Pop(p);
                                Insertar(c,caracter);
                                if(!ValidaVacioP(p))
                                {
                                    if(ElementoTope(p)==43 ||ElementoTope(p)==45)
                                    {
                                        caracter=Pop(p);
                                        Insertar(c,caracter);
                                        Push(p,operacion[i]);
                                    }
                                    else
                                    {
                                        Push(p,operacion[i]);
                                    }
                                }
                                else
                                {
                                    Push(p,operacion[i]);
                                }
                            }
                            else if(ElementoTope(p)==43 ||ElementoTope(p)==45)
                            {
                                caracter=Pop(p);
                                Insertar(c,caracter);
                                Push(p,operacion[i]);
                            }
                            else
                            {
                                Push(p,operacion[i]);
                            }
                        }
                        else
                        {
                            Push(p,operacion[i]);
                        }
                    }
                    else if(ElementoTope(p)==42 ||ElementoTope(p)==47)
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        if(!ValidaVacioP(p))
                        {
                            if(ElementoTope(p)==43 ||ElementoTope(p)==45)
                            {
                                caracter=Pop(p);
                                Insertar(c,caracter);
                                Push(p,operacion[i]);
                            }
                            else
                            {
                                Push(p,operacion[i]);
                            }
                        }
                        else
                        {
                            Push(p,operacion[i]);
                        }
                    }
                    else if(ElementoTope(p)==43 ||ElementoTope(p)==45)
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        Push(p,operacion[i]);
                    }
                    else
                    {
                        Push(p,operacion[i]);
                    }
                }
                else
                {
                    Push(p,operacion[i]);
                }
            }
            else if(operacion[i]==42 || operacion[i]==47)// * o /
            {
                if(!ValidaVacioP(p))
                {
                    if(ElementoTope(p)==94)
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        if(!ValidaVacioP(p))
                        {
                            if(ElementoTope(p)==42 ||ElementoTope(p)==47)
                            {
                                caracter=Pop(p);
                                Insertar(c,caracter);
                                Push(p,operacion[i]);
                            }
                            else if(ElementoTope(p)==40 || ElementoTope(p)==91)
                            {
                                Push(p,operacion[i]);
                            }
                            else
                            {
                                Insertar(c,operacion[i]);
                            }
                        }
                        else
                        {
                            Push(p,operacion[i]);
                        }
                    }
                    else if(ElementoTope(p)==42 ||ElementoTope(p)==47)
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        Push(p,operacion[i]);
                    }
                    else if(ElementoTope(p)==40 || ElementoTope(p)==91)
                    {
                        Push(p,operacion[i]);
                    }
                    else
                    {
                        Insertar(c,operacion[i]);
                    }
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
                    if(ElementoTope(p)==operacion[i])
                    {
                        caracter=Pop(p);
                        Insertar(c,caracter);
                        Push(p,operacion[i]);
                    }
                    else if(ElementoTope(p)==40 || ElementoTope(p)==91)
                    {
                        Push(p,operacion[i]);
                    }
                    else
                        Insertar(c,operacion[i]);
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
            {
                Insertar(c,operacion[i]);
            }
            printf("\n\nPaso: %i",i+1);
            printf("\nSimbolo analizado: %c",operacion[i]);
            printf("\nPila: ");
            ListarP(p);
            printf("\nExpresion en notacion prefija: ");
            Listar(c);
        }
        for(j=p->tope;j>=0;j--)
        {
            caracter=Pop(p);
            Insertar(c,caracter);
            printf("\n\nPaso: %i",i+1);
            printf("\nSimbolo analizado: ");
            printf("\nPila: ");
            ListarP(p);
            printf("\nExpresion en notacion prefija: ");
            Listar(c);
        }
	}
	else
	{
		printf("Error la operacion ingresada no es correcta...");
	}

	return 0;
}
