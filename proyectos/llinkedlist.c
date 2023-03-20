
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo * siguiente;
} NODO;

 NODO * CrearNodo(int dato);
 int InsertarInicio(NODO **cabeza, int dato);
 int InsertarFinal(NODO **cabeza, int dato);
 void ImprimirLista(NODO *cabeza);


int main (){
    
    NODO *cabeza = NULL;
    InsertarInicio(&cabeza, 3);
    InsertarFinal(&cabeza, 0);
    InsertarFinal(&cabeza, 6);
    InsertarFinal(&cabeza, 0);
    InsertarFinal(&cabeza, 4);
    InsertarFinal(&cabeza, 5);
    InsertarFinal(&cabeza, 3);
    InsertarFinal(&cabeza, 0);

    ImprimirLista(cabeza);
    return 0 ;
}

NODO * CrearNodo(int dato) {
    NODO *nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));

    if (nuevo != NULL) {
        nuevo -> dato = dato;
        nuevo -> siguiente = NULL;
    }
    return nuevo;
}

int InsertarInicio (NODO **cabeza, int dato) {
    NODO *nuevo = NULL;
    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        nuevo ->siguiente = *cabeza;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}
void ImprimirLista(NODO *cabeza){

    NODO *nAux = cabeza;

    while( nAux != NULL){
        printf("%d ", nAux ->dato);
        nAux= nAux ->siguiente;
    }

}
int InsertarFinal(NODO **cabeza, int dato){

   NODO  *nuevo = NULL, *nAux= * cabeza;

   nuevo = CrearNodo(dato);

   if( nuevo != NULL){
        while(nAux ->siguiente!=NULL){
            nAux  = nAux ->siguiente;
        }
        nAux ->siguiente= nuevo;
        return 1;
   }

   return 0;
}

