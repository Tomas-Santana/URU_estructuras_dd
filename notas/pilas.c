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
    COCHE* cocheNuevo = NULL;
    cocheNuevo = malloc(sizeof(COCHE));

    if (cocheNuevo != NULL) {
        cocheNuevo->color=color;
        cocheNuevo->marca=marca;
        cocheNuevo->modelo=modelo;
        strcpy(cocheNuevo->matricula, matricula);
    }
    return cocheNuevo;
}

NODO* crearNodo(COCHE* coche) {
    NODO* nuevo = NULL;
    nuevo = malloc(sizeof(NODO));

    if (nuevo != NULL) {
        nuevo->dato = coche;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

NODO* crearPila(){
}