#ifndef PILAYCOLA_H_INCLUDED
#define PILAYCOLA_H_INCLUDED

typedef struct
{
    int max; //tamaño de la pila
    char *arreglo;
    int tope;
}pila;

pila *getPila(int max);
char Pop(pila *p);
int Vacio(pila *p);
int validaEspacio(pila *p);
void Push(pila *p,char dato);
void Listar(pila *p);

typedef struct
{
    int max; //tamaño de la cola
    char *arreglo;
    int t;
    int h;
}cola;

cola *getcola(int max);
int validaEspacioCola(cola *c);
int VacioCola(cola *c);
char borrar(cola *c);
void insertarCola(cola *c,char dato);
void listarCola(cola *c);



#endif // PILAYCOLA_H_INCLUDED
