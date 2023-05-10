#include <cstdlib>
#include "queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}


void destroyQueue(Queue* queue) {
    while(!isQueueEmpty(queue)) {
        free(pop(queue));
    }
    free(queue);
}


bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}


void push(Queue* queue, void* object) {
    
    Qnoeud* temp = (Qnoeud*)malloc(sizeof(Qnoeud));
    temp->object = object;
    temp->next = NULL;

    
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    
    queue->rear->next = temp;
    queue->rear = temp;
}

void insert(Queue* queue, void* object, bool (*compare)(void* left, void* right)) {
    Qnoeud* temp = (Qnoeud*)malloc(sizeof(Qnoeud));
    temp->object = object;

    
    if (queue->front == NULL || compare(object, queue->front->object)) {
        temp->next = queue->front;
        queue->front = temp;

        
        if (queue->rear == NULL) {
            queue->rear = temp;
        }
    } else {
        
        Qnoeud* current = queue->front;
        while (current->next != NULL && !compare(object, current->next->object)) {
            current = current->next;
        }
        
        temp->next = current->next;
        current->next = temp;

        if (current == queue->rear) {
            queue->rear = temp;
        }
    }
}



void* pop(Queue* queue) {
    
    if (queue->front == NULL)
        return NULL;

    
    Qnoeud* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    void* object = temp->object;
    free(temp);

    return object;
}

void* peek(Queue* queue) {
    if (isQueueEmpty(queue))
        return NULL;
    return queue->front->object;
}

bool exists(Queue* queue, void* object, bool (*compare)(void* a, void* b)) {
    Qnoeud* current = queue->front;
    while (current != NULL) {
        if (compare(object, current->object)) {
            return true;
        }
        current = current->next;
    }
    return false;
}
