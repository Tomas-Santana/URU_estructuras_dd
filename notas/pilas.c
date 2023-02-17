// Una pila es basicamente una lista enlazada cuyos elementos solo pueden quitarse y ponerse en el principio. Tal cual una pila real. Vemos ejemplo de Eli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct coche {
    char matricula[10];
    int modelo;
    int color;
    int marca;

}COCHE;

typedef struct nodo {
    COCHE* dato;
    struct nodo* siguiente;
}NODO;

typedef struct pila {
    NODO* tope;
    int total;
}PILA;

COCHE* crearCoche(char matricula[10], int modelo, int color, int marca){
    COCHE* 
}