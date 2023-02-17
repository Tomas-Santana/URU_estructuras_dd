#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
    struct nodo* anterior;
}NODO;


NODO *CrearNodo(int);
int InsertarIncio(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);

int main() {
  NODO* cabeza = NULL;
  
}


NODO* CrearNodo(int dato) {
  NODO *nuevo = NULL;
  nuevo = malloc(sizeof(NODO));

  if (nuevo != NULL)
  {
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
  }

  return nuevo;
}

int InsertarIncio(NODO **cabeza, int dato) { 
  NODO* nuevo = NULL;
  nuevo = CrearNodo(dato);

  if (nuevo != NULL) {
    nuevo->siguiente = *cabeza;
    nuevo->anterior = NULL;
    if (*cabeza != NULL) {
      (*cabeza)->anterior = nuevo;
    }
    *cabeza = nuevo;

    return 1;
  }
  return 0;
}

void ImprimirLista(NODO *cabeza) {
  NODO *aux = cabeza;


  while (aux != NULL) {
    printf("%d ", aux->dato);
    aux = aux->siguiente;
  }  
}


