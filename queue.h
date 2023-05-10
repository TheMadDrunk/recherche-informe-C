#ifndef QUEUE_H
#define QUEUE_H

typedef struct Qnoeud {
    void* object;
    struct Qnoeud* next;
} Qnoeud;


typedef struct Queue {
    Qnoeud* front; 
    Qnoeud* rear; 
} Queue;


Queue* createQueue();

void destroyQueue(Queue* queue);

bool isQueueEmpty(Queue* queue);

void push(Queue* queue, void* object);

//allow using the queue as a priority queue, needs the compare function of the object
void insert(Queue* queue, void* object, bool (*compare)(void* left, void* right));

void* pop(Queue* queue);

void* peek(Queue* queue);

bool exists(Queue* queue, void* object, bool (*compare)(void* a, void* b));

#endif // QUEUE_H
