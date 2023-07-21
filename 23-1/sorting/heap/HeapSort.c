#include <stdio.h>
#include "UHeap.h"

int PriComp(Data d1, Data d2) {

    // 오름차순 정렬
    return d2 - d1;

}

void HeapSort(Data arr[], int len, PriorityComp pc) {

    Heap h;
    int i;

    HeapInit(&h, pc);

    for (i = 0; i < len; i++) {
        HInsert(&h, arr[i]);
    }
    
    for (i = 0; i < len; i++) {
         arr[i] = HDelete(&h);
    }


}

int main() {

    Data arr[4] = {3, 2, 4, 1};
    int len = sizeof(arr) / sizeof(int);
    HeapSort(arr, len, PriComp);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}