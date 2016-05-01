#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

//Definicion de la Pila
typedef struct
{
    char *arreglo;
    int tope;
    int max;
}Pila;

//Definicion de la Cola
typedef struct
{
    char *arreglo;
    int header;
    int tail;
    int max;
}Cola;

//Metodos usados por la Pila
void Push(Pila *p, char dato);
char Pop(Pila *p);
void ListarP(Pila *p);
int ValidaEspacioP(Pila *p);
int ValidaVacioP(Pila *p);
char ElementoTope(Pila *p);
//Metodos usados por la Cola
void Insertar(Cola *c,char dato);
void Borrar(Cola *c);
void Listar(Cola *c);
int ValidaVacio(Cola *c);
int ValidaLleno(Cola *c);
int ValidaEspacio(Cola *c);
//Otros metodos
int ValidaCadena(char operacion[],int tam);
float eval(Cola *c);
int isdigit(char symb);
float oper(char symb, float op1, float op2);

#endif // METODOS_H_INCLUDED
