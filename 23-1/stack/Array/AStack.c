#include <stdio.h>
#include <stdlib.h>
#include "AStack.h"

// 스택 초기화
void StackInit(Stack * pstack) {
    pstack->top = -1;
}

// 스택에 데이터가 있는지 확인
int SIsEmpty(Stack * pstack) {

    if (pstack->top == -1) {
        return TRUE;
    }
    
    return FALSE;

}

// 데이터 저장
void SPush(Stack * pstack, Data data) {

    int cur = ++(pstack->top);
    pstack->data[cur] = data;
    
}

// 데이터 삭제
Data SPop(Stack * pstack) {

    if (SIsEmpty(pstack)) {
        exit(-1);
    }
    
    int remove = (pstack->top)--;
    return pstack->data[remove];

}

// 데이터 조회
Data SPeek(Stack * pstack) {


    if (SIsEmpty(pstack)) {
        exit(-1);
    }

    return pstack->data[pstack->top];

}

