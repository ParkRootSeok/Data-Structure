#ifndef __L_STACK_H__
#define __L_STACK_H__

#define TRUE	1
#define FALSE	0

/* Define Stack ADT */

typedef int Data;

typedef struct __node {

    Data data;
    struct __node * next;

} Node;


typedef struct __stack {

    Node * top;
    
} Stack;

// 스택 초기화
void StackInit(Stack * pstack);

// 스택에 데이터가 있는지 확인
int SIsEmpty(Stack * pstack);

// 데이터 저장
void SPush(Stack * pstack, Data data);

// 데이터 삭제
Data SPop(Stack * pstack);

// 데이터 조회
Data SPeek(Stack * pstack);


#endif