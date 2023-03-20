# Arboles binarios

Divide la informacion en mitades. Se usa en la busqueda binaria (en listas ordenadas) y en los compiladores.

## Operaciones elementales del arbol binario:

- Insertar nodo (rama u hoja)
- Buscar nodo
- Eliminar nodo
- Recorrer arbol
- Balancear arbol


## Estructura del arbol binario

|#Nodos a la izquierda|Raiz|#Nodos a la derecha|
|---|---|---|

```C
typedef struct arbol {
    int totalIzquierda;
    Nodo *raiz;
    int totalDerecha
}
```
El nodo raiz apunta hacia el nodo anterior, su propia raiz.

## Estructura del nodo
|Nodo izquierdo|#Hijos izquierdos|Nodo padre|Dato|#Hijos derechos|Nodo derecho|
|---|---|---|---|----|---|

```C
typedef struct nodo {
    struct nodo* izquierda;
    int hijosIzquierda;
    struct nodo* padre;
    int dato;
    int hijosDerecha;
    struct nodo* derecha;
}
```

## Funciones del arbol

### Crear arbol

```C
Arbol* crearArbol() {
    Arbol* nuevo = (Arbol*)malloc(sizeof(Arbol));
    if (nuevo!=NULL) {
        nuevo->totalIzquierda=0;
        nuevo->totalDerecha=0;
        nuevo->raiz=NULL;
    return nuevo;
    }
}
```

### Crear nodo

```C
Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo!=NULL) {
        nuevo->izquierda=NULL;
        nuevo->padre=NULL;
        nuevo->derecha=NULL;
        nuevo->hijosIzquierda=0;
        nuevo->hijosDerecha=0;
        nuevo->dato=dato;
    }
    return nuevo;
}
```

### Insertar nodo

Debe comprobarse si el arbol esta vacio. Se implementa la siguiente funcion.

```C
int estaVacio(Arbol* arbol) {
    if (arbol->raiz==NULL) 
        return 1;
    else 
        return 0;
}
```

La funcion para insertar un nodo quedaria de la siguiente manera

```C
void insertarNodo(Arbol* arbol, Nodo* nodo) {
    if (estaVacio(arbol)) {
        arbol->raiz=nodo;
    }
    else { 
    // Si el arbol no esta vacio
    

    }
}
```

[Implementacion del arbol binario en C.](arbolbinario.c)