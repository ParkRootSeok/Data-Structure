#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE	1
#define FALSE	0
#define LENGTH	100

typedef int Data;

/* Circular Queue ADT */
typedef struct __cQueue {

    int front;  // 첫 번째 데이터 위치
    int rear;   // 마지막 데이터 위치
    Data arr[LENGTH];

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