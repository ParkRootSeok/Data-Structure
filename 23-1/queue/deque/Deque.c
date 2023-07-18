#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void QueueInit(Deque * dq) {

    dq->head = NULL;
    dq->tail = NULL;

}

void DIsEmpty(Deque * dq) {

    if (dq->head == NULL) {
        return TRUE;
    }

    return FALSE;

}

void DAddFirst(Deque * dq, Data data) {

    Node * newNode = (Node *)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = dq->head;

    if (DIsEmpty(dq)) {
        dq->tail = newNode;
        newNode->next = NULL;
    } else {
        dq->head->prev = newNode;
    }
    
    newNode->prev = NULL
    dq->head = newNode;

}

void DAddLast(Deque * dq, Data data) {
    
    Node * newNode = (Node *)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->prev = dq->tail;

    if (DIsEmpty(dq)) {
        dq->head = newNode;
        newNode->next = newNode->prev = NULL;
    } else {
        dq->tail->next = newNode;
    }
    
    newNode->next = NULL;
    dq->tail = newNode;

}

Data DRemoveFirst(Deque * dq) {

    if (DIsEmpty(dq)) {
        exit(-1);
    }

    Node * rNode = dq->head;
    Data rData = rNode->data;

    dq->head = rNode->next;
    free(rNode);
    
    if (dq->head == NULL)    {
        dq->tail = NULL;
    } else {
        dq->head->prev == NULL;
    }


    return rData;

}

Data DRemoveLast(Deque * dq) {
    
    if (DIsEmpty(dq)) {
        exit(-1);
    }

    
    Node * rNode = dq->tail;
    Data rData = rNode->data;


    dq->tail = rNode->prev;
    free(rNode);

    if (dq->tail == NULL)    {
        dq->head = NULL;
    } else {
        dq->tail->next = NULL;
    }

    return rData;

}

Data DGetFirst(Deque * dq) {

    return dq->head->data;

}

Data DGetLast(Deque * dq) {

    return dq->tail->data;

}
