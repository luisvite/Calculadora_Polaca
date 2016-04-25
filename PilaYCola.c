#include<stdio.h>
#include<stdlib.h>
#include"PilaYCola.h"

pila *getPila(int max)
{
    pila *Pila;
    Pila = (pila *)malloc(sizeof(pila));
    Pila -> max = max;
    Pila -> arreglo = (char *)malloc(sizeof(char)*Pila->max);
    Pila -> tope = -1;
    return Pila;
}

int validaEspacio(pila *p)
{
    return p->tope < p->max-1;
}

int Vacio(pila *p)
{
    return p->tope == -1;
}

char Pop(pila *p)
{
    char aux = p->arreglo[p->tope];
    p->tope--;
    return aux;
}

void Push(pila *p,char dato)
{
    p->tope++;
    p->arreglo[p->tope] = dato;
}

void Listar(pila *p)
{
    int i;
    for(i=p->tope; i >= 0; i--)
        printf("%c\n",p->arreglo[i]);
}

//Cola
cola *getcola(int max)
{
    cola *Cola;
    Cola = (cola *)malloc(sizeof(cola));
    Cola -> max = max;
    Cola -> arreglo = (char *)malloc(sizeof(char)*Cola->max);
    Cola -> t = -1;
    Cola -> h = -1;
    return Cola;
}

int validaEspacioCola(cola *c)
{
    return c->t < c->max-1;
}

int VacioCola(cola *c)
{
    return c->h == -1;
}

char borrar(cola *c)
{
    char aux = c->arreglo[c->h];
    if(c->h == c->t)
    {
        printf("Arreglo vacio\n");
        c->h=-1;
        c->t=-1;
    }
    else
        c->h++;
    return aux;

}

void insertarCola(cola *c,char dato)
{
    if (c->h == -1)
        c->h++;
    c->t++;
    c->arreglo[c->t] = dato;
}

void listarCola(cola *c)
{
    int i;
    for(i=c->h; i<=c->t; i++)
        printf("%c\t",c->arreglo[i]);
}

