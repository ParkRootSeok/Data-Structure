#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

void QueueInit(Queue * q) {

    q->front = NULL;
    q->rear = NULL;

}


void QIsEmpty(Queue * q) {

    if (q->front == NULL) {
        return TRUE;
    }

    return TURE;

}


void Enqueue(Queue * q, Data data) {

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (QIsEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }

    q->rear->next = newNode;
    q->rear = newNode;

}

Data dequeue(Queue * q) {

    if (QIsEmpty(q)) {
        exit(-1);
    }

    Node * remvoeNode = q->front;
    Data removeData = remvoeNode->data;

    q->front = remvoeNode->next;
    free(remvoeNode);

    return removeData;

}

Data QPeek(Queue * q) {

   if (QIsEmpty(q)) {
        exit(-1);
    }

    return q->front->data;
    
}
