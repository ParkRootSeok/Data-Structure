#include <stdio.h>
#include "LQueue.h"

#define BUCKET_NUMBER 10

void RadixSort(int arr[], int num, int maxLen) {

    Queue buckets[BUCKET_NUMBER];
    int bi, pos, di, divfac = 1, radix;

    for (bi = 0; bi < BUCKET_NUMBER; bi++) {    // 1 ~ 10에 대한 버킷 생성
        QueueInit(&buckets[bi]);
    }

    for (pos = 0; pos < maxLen; pos++) {    // 총 5자리에 대한 기수 정렬 실행
        
        for (di = 0; di < num; di++) {
            
            radix = (arr[di] / divfac) % 10;    
            Enqueue(&buckets[radix], arr[di]);

        }

        for (bi = 0, di = 0; bi < BUCKET_NUMBER; bi++) {
            
            while (!QIsEmpty(&buckets[bi])) {
                arr[di++] = dequeue(&buckets[bi]); 
            }

        }
        
        divfac *= 10;

    }
    

}


int main() {

    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int len = sizeof(arr) / sizeof(int);
    RadixSort(arr, len, 5);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}