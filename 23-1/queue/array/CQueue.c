#include <stdio.h>
#include <stdlib.h>
#include "CQueue.h"


void QueueInit(Queue * q) {
    q->front = 0;
    q->rear = 0;
}

void QIsEmpty(Queue * q) {

    if (q->front == q->rear) {
        return TRUE;
    }
    
    return FALSE;

}
 
int NextPosIdx(int pos) {

    if (pos == LENGTH - 1) {    // 배열이 끝에 도달한 경우 초기화
        return 0;
    }

    return pos + 1;
    
}

void Enqueue(Queue * q, Data data) {

    if (NextPosIdx(q->rear) == q->front) {
        exit(-1);
    }

    q->rear = NextPosIdx(q->rear);
    q->arr[q->rear] = data;

}


Data dequeue(Queue * q) {

    if (QIsEmpty(q)) {
        exit(-1);
    }

    q->front = NextPosIdx(q->front);
    return q->arr[(q->front)];

}

Data QPeek(Queue * q) {

     if (QIsEmpty(q)) {
        exit(-1);
    }


    return q->arr[NextPosIdx(q->front)];

}
