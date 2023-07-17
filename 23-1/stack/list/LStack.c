#include <stdio.h>
#include <stdlib.h>
#include "LStack.h"

// 스택 초기화
void StackInit(Stack * pstack) {
    pstack->top = NULL;
}

// 스택에 데이터가 있는지 확인
int SIsEmpty(Stack * pstack) {

    if (pstack->top == NULL) {
        return TRUE;
    }
    
    return FALSE;

}

// 데이터 저장
void SPush(Stack * pstack, Data data) {

    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pstack->top;
    pstack->top = newNode;
    
}

// 데이터 삭제
Data SPop(Stack * pstack) {

    if (SIsEmpty(pstack)) {
        exit(-1);
    }
    
    Node * removeNode = pstack->top;
    Data removeData = removeNode->data;

    pstack->top = removeNode->next;
    
    free(removeNode);
    return removeData;

}

// 데이터 조회
Data SPeek(Stack * pstack) {


    if (SIsEmpty(pstack)) {
        exit(-1);
    }

    return pstack->top->data;

}

