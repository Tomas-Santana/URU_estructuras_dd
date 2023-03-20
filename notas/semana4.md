# Listas doblemente enlazadas

Son listas en las cuales los nodos apuntadores al nodo siguiente y al nodo anterior. Son convenientes cuando necesitamos acceder a los elementos de la lista en cualquier orden.

Similar a las listas enlazadas, se declaran como una estructura (nodo), que tiene un dato (o datos) y cuentan con un apuntador de su mismo tipo que toma la direccion del nodo siguiente. En las dll, el nodo cuenta ademas con un apuntador al nodo anterior.

```C
typedef struct nodo {
    // Dato
    int dato
    // Apuntadores
    struct nodo* siguiente; 
    struct nodo* anterior;
}NODO; // Creacion del tipo de dato (a partir de ahora lo llamamos NODO)
```
[Implementacion completa de la lista doblemente enlazada en C.](doublylinkedlist.c)


