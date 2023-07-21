#include <stdio.h>
#include <stdlib.h>


void MergeTowArea(int arr[], int left, int mid, int right) {

    int i;
    int fIdx = left;        // 좌측 분할 영역 시작점
    int rIdx = mid + 1;     // 우측 분할 영역 시작점

    int * sortArr = (int *)malloc(sizeof(int) * rIdx);
    int sIdx = left;

    while (fIdx <= mid && rIdx <= right) {  // 좌, 우 영역에 대해 정렬

        if (arr[fIdx] <= arr[rIdx]) {   // 좌측이 우선순위가 높을 때
            sortArr[sIdx] = arr[fIdx++];
        } else {                        // 우측이 우선순위가 높을 때
            sortArr[sIdx] = arr[rIdx++];
        }

        sIdx++;
        
    }

    // 정렬이 이루어지지 않은 남은 원소들도 정렬
    if (fIdx > mid) {   // 좌측 영역만 정렬 완료했을 때
        
        for (i = rIdx; i <= right; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
        
    } else {
        for (i = fIdx; i <= mid; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    }

    for (i = 0; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);

}

void MergeSort(int arr[], int left, int right) {

    if (left > right) {
        return;
    }

    int mid = (left + right) / 2;

    /* 배열 분할(mid 기준) */
    MergeSort(arr, left, mid);          // 좌측 영역 분할
    MergeSort(arr, mid + 1, right);     // 우측 영영 분할
    
    MergeTowArea(arr, left, mid, right);    // 분할 된 영역 결합(정렬 포함)

}



int main() {

    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int len = sizeof(arr) / sizeof(int);
    MergeSort(arr, 0, len-1);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}