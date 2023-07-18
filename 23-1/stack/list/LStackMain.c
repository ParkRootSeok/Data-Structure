#include <stdio.h>
#include "LStack.c"

int main(void) {
    
    Data data;
    Stack stack;

    StackInit(&stack);
    
    while (1) { // 데이터 삽입

        printf("자연수 입력 : ");
        scanf("%d", &data);

        if(data == -1) break;

        SPush(&stack, data);

    }

    while (!SIsEmpty(&stack)) {
        printf("%d ", SPop(&stack));
    } printf("\n\n");
    
    return 0;
    
}