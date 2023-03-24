#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

// estructuras
typedef struct Drink {
    char name[MAX_STRING];
    float price; // en dolares
    int vol; // en mililitros
}Drink;
typedef struct Node
{
    Drink content;
    struct Node* next;
}Node;
typedef struct Queue
{
    Node *first, *last;
}Queue;

typedef struct QueueDrink {
    Drink drink;
    Queue* queue;
}QueueDrink;


// funciones
Node* newNode(Drink drink) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new!=NULL){
        new->content=drink;
        new->next=NULL;
    }
    return new;
}

Queue* newQueue() {
    Queue* new = (Queue*)malloc(sizeof(Queue));
    if (new!=NULL) {
        new->first=new->last=NULL;
    }
    return new;
}

QueueDrink newQueueDrink() {
    QueueDrink new;
    new.drink.name[0]='\0';
    new.drink.price=0;
    new.drink.vol=0;
    new.queue=newQueue();
    return new;
}

void addDrink(Queue** queue, Drink drink) {
    Node *new = newNode(drink);
    if ((*queue)->first==NULL) {
        (*queue)->first=(*queue)->last=new;
    }
    else {
        (*queue)->last->next=new;
        (*queue)->last=new;
    }
}
// Crea una copia de una cola, pero sin relacionar los punteros. 
Queue* copyQueue(Queue* queue) {
    Queue* new = newQueue();
    Node* actual = queue->first;
    while (actual!=NULL)
    {
        addDrink(&new, actual->content);
        actual=actual->next;
    }
    return new;
    
}

// Devuelve una cola con el nuevo elemento agregado. No modifica la cola original.
Queue* enQueue(Queue* queue, Drink drink) {
    Queue* returnQ = copyQueue(queue);
    Node* returnN = newNode(drink);
    if (returnQ->first==NULL) {
        returnQ->first=returnQ->last=returnN;
    }
    else {
        returnQ->last->next=returnN;
        returnQ->last=returnN;
    }
    return returnQ; 
}

// Devuelve una estructura con la bebida y la cola sin el primer elemento. No modifica la cola original.
QueueDrink deQueue(Queue* queue) {
    QueueDrink returnQD;
    if (queue->first==NULL) {
        returnQD.drink.name[0]='\0';
        returnQD.drink.price=0;
        returnQD.drink.vol=0;
        returnQD.queue=NULL;
    }
    else {
        returnQD.drink=queue->first->content;
        returnQD.queue=copyQueue(queue);
        returnQD.queue->first=returnQD.queue->first->next;
    }
    return returnQD;
}

// Imprime los elementos de la cola.
void printQueue(Queue* queue) {
    Node* actual = queue->first;
    int i=1;
    printf("Advertencia: Nombres truncados a 10 caracteres, precios y volumenes a 5 digitos.\n");
    printf("Bebidas disponibles:\n");
    while (actual!=NULL)
    {
        printf("Bebida #%i--------------------------------------------\n"
            "|Nombre:%-10s|Precio:%-5.2f USD|Volumen:%-5i mL|\n"
            "-----------------------------------------------------\n"
        
        ,i, actual->content.name, actual->content.price, actual->content.vol%100000);

        actual=actual->next;
        i++;
    } 
}

int main() {
    Drink coke= {"Coke", 12, 123};
    Drink greenTea= {"Green Tea", 12, 1234};
    Drink fanta= {"Fanta", 12, 123};
    Drink sprite= {"Sprite", 12, 1234};
    Drink pepsi= {"Pepsi", 12, 1234};

    Queue* cola = newQueue();
    cola = enQueue(cola, greenTea);
    cola = enQueue(cola, coke);
    cola = enQueue(cola, fanta);
    cola = enQueue(cola, sprite);
    printf("Creando una cola y agregando unas bebidas.\n");
    printQueue(cola);

    QueueDrink colabebida = deQueue(cola);
    printf("Sacando una bebida de la cola.\n"); 
    printf("Bebida sacada: %s\n", colabebida.drink.name);
    cola = colabebida.queue;
    printf("Cola actual:\n\n");
    printQueue(cola);



    return 0;

}
