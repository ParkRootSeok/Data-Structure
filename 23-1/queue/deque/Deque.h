#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct __node {

    Data data;
    struct __node * next;
    struct __node * prev;

} Node;

/* Queue ADT */
typedef struct __deque {

    Node * head;
    Node * tail;

} Deque;

void QueueInit(Deque * dq);     // 덱 초기화

void DIsEmpty(Deque * dq);      // 덱에 데이터가 있는지 확인

// 데이터 저장
void DAddFirst(Deque * q, Data data);
void DAddLast(Deque * q, Data data);

// 데이터 삭제
Data DRemoveFirst(Deque * q);
Data DRemoveLast(Deque * q);


// 데이터 조회
Data DGetFirst(Deque * q);
Data DGetLast(Deque * q);

#endif