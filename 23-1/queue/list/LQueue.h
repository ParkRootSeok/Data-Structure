#ifndef __L_QUEUE_H__
#define __L_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct __node {

    Data data;
    struct __node * next;

} Node;

/* Queue ADT */
typedef struct __LQueue {

    Node * front;
    Node * rear;

} Queue;

void QueueInit(Queue * q);
// 큐 초기화

void QIsEmpty(Queue * q);
// 큐에 데이터가 있는지 확인

void Enqueue(Queue * q, Data data);
// 데이터 저장

Data dequeue(Queue * q);
// 데이터 삭제

Data QPeek(Queue * q);
// 첫 번째 데이터 조회

#endif