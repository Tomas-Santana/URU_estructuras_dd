#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_STRING 20

typedef struct drink
{
    char name[MAX_STRING];
    float price; //price in USD
    int vol; // volume in mL
}Drink;

typedef struct node
{
    Drink content;
    struct Node* next;
}Node;

typedef struct queue
{
    Node *first, *last;
}Queue;

struct QueueDrink 
{
    Queue* Q;
    Drink D;
};


Node* newNode(Drink content) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new!=NULL) {
        new->content=content;
        new->next=NULL;
    }
    return new;
}

Queue* newQueue() {
    Queue* new = (Queue*)malloc(sizeof(Queue));
    if (new!=NULL) {
        new->first=new->last=NULL;
    }
}

void addDrink(Queue* queue, Drink drink) {
    Node* new = newNode(drink);
    if (queue->first==NULL) 
    { //if queue is empty
        queue->first=queue->last=new;
    }
    else
    { // if queue is not empty
        queue->last=queue->last->next=new;
    }
}

Queue** copyQueue(Queue** queue) {
    
    Queue* new = newQueue();
    Node* actual = (*queue)->first;
    while (actual != NULL) {
        addDrink(new, actual->content);
        actual = actual->next;
    }  
    return &new;
}

//incompatible pointer type warning. Corre
Queue* qPush(Queue** queue, Drink val){ 
    Queue** returnQueue = copyQueue(queue);
    Node* returnNode = newNode(val);
    if ((*returnQueue)->first==NULL) 
    { //Si la cola esra vacia
        (*returnQueue)->first=(*returnQueue)->last=returnNode;
    }
    else
    { // Si la cola no esta vacia
        (*returnQueue)->last->next=returnNode;
        (*returnQueue)->last=returnNode;
    }
    return *returnQueue;
}
//incompatible pointer type warning. No corre
struct QueueDrink* qPop(Queue* queue) { //Devuelve una estructura con la nueva cola y el elemento sacado
    Queue* returnQueue = queue;
    Node* returnNode = returnQueue->first;
    returnQueue->first = returnNode->next;
    struct QueueDrink* returnQueueDrink = malloc(sizeof(struct QueueDrink));
    returnQueueDrink->Q = returnQueue;
    returnQueueDrink->D = returnNode->content;
    return returnQueueDrink;

}

void iterateQueue(Queue* queue, Drink (f)(Drink))
{
    Node* actual = queue->first;
    while (actual != NULL)
    {
        f(actual->content);
        actual=actual->next;
    }
}

Drink printQueue(Drink drink) {
    printf("------------------------------------\n"
    "|%-20s|%-6.2f|%-6i|\n"
    "------------------------------------\n",
    drink.name, drink.price, drink.vol);
}

int main() {
    Drink pepsi = {"Pepsi", 1.5, 550};
    Drink cocaCola = {"Coca-Cola", 2.5, 1500};
    Drink sevenUp = {"Seven-Up", 3, 2000 };

    Queue* queue = newQueue();
    queue = qPush(&queue, pepsi);
    Queue* queue2 = qPush(&queue, cocaCola);
    iterateQueue(queue, printQueue);
    printf("\n\n\n\n");
    iterateQueue(queue2, printQueue);
}






