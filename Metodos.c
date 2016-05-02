#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "Metodos.h"

//Metodos usados por la Pila
void Push(Pila *p, char dato)
{
    p->tope++;
    p->arreglo[p->tope]=dato;
}

char Pop(Pila *p)
{
    char aux;
    aux=ElementoTope(p);
    p->tope--;
    return aux;
}

void ListarP(Pila *p)
{
    int i;
    for(i=p->tope;i>=0;i--)
    {
        printf("%c",p->arreglo[i]);
    }
}

int ValidaEspacioP(Pila *p)
{
    return p->tope<p->max-1;
}

int ValidaVacioP(Pila *p)
{
    return p->tope==-1;
}

char ElementoTope(Pila *p)
{
    return p->arreglo[p->tope];
}

//Metodos usados por la cola
void Insertar(Cola *c,char dato)
{
    if(c->header==-1)
        c->header++;
    c->tail++;
    c->arreglo[c->tail]=dato;
}

void Borrar(Cola *c)
{
    if(c->header==c->tail)
    {
        c->header==-1;
        c->tail==-1;
    }
    else
        c->header++;
}

void Listar(Cola *c)
{
    int i;
    for(i=c->header;i<=c->tail;i++)
        printf("%c",c->arreglo[i]);
}

int ValidaVacio(Cola *c)
{
    return(c->header==-1);
}

int ValidaEspacio(Cola *c)
{
    return(c->tail<c->max-1);
}

//Otros metodos
int ValidaCadena(char operacion[],int tam)
{
	int i, acumulador=0;
    if(operacion[0]==47 || operacion[0]==42 || operacion[0]==43 || operacion[0]==45 || operacion[0]==94)
        return 0;
    else
        if(operacion[tam-1]==47 || operacion[tam-1]==42 || operacion[tam-1]==43 || operacion[tam-1]==45 || operacion[tam-1]==94)
            return 0;
    for(i=0; i<=tam; i++)
    {
        if(operacion[i]>=47 && operacion[i]<=57 || operacion[i]>=40 && operacion[i]<=43 || operacion[i]==45 || operacion[i]==91 || operacion[i]==93 || operacion[i]==94)
            acumulador = acumulador +1;
    }
    if(acumulador == tam)
        return 1;
    return 0;
}
//aqui empiza la funcion para evaluar
float eval(Cola *c)
{
    int position;
    float opnd1,opnd2, value;
    Pila *opndstk;
    opndstk=(Pila*)malloc(sizeof(Pila));
    opndstk->arreglo=(char*)malloc(50*sizeof(char));
    opndstk->tope=-1;
    opndstk->max=50;
    for(position = 0; position <= c->tail ; position++)
    {
        if (isdigit(c->arreglo[position])){
                /* operando--convertir el caracter que*/
                /* representa el digito float y*/
                /* se coloca en la pila */
                Push(opndstk, (float)(c->arreglo[position]-'0'));
        }else{
                opnd2= Pop(opndstk);
                opnd1= Pop(opndstk);
                value = oper(c->arreglo[position], opnd1, opnd2);
                Push(opndstk, value);
        }
    }       /* fin del else*/
    return (Pop(opndstk));
}/*fin del eval*/


int isdigit(char symb)
{
    return(symb>='0' &&  symb<='9');
}

float oper(char symb, float op1, float op2)
{
    switch(symb)
    {
        case '+':
            return (op1 + op2);
        case '-':
            return (op1 - op2);
        case '*':
            return (op1 * op2);
        case '/':
            return(op1 / op2);
        case '$':
            return (pow(op1, op2));
       // exit(1);
    }/*fin de awicth*/

}/*fin de oper*/

