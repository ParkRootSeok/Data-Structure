#include <stdio.h>

/*
    * 재귀적 이진 탐색
*/

int recursiveBinarySearch(int* arr, int first, int last, int target) {    

    int mid;

    if (first > last) { // 인덱스가 교차한 경우 예외 처리
        return -1;
    }

    mid = (first + last) / 2;
    printf("search arr[%d]\n", mid);
    if (arr[mid] == target) { // 검색 성공한 경우 예외 처리
        return mid;
    }

    if (arr[mid] > target) {      
        return recursiveBinarySearch(arr, first, mid - 1, target);
    } else {
        return recursiveBinarySearch(arr, mid + 1, last, target);
    }

}

int main() {
    
    int arr[] = { 1, 2, 3, 7, 9, 12, 21, 23, 27};


    while (1) {
        
          
        int idx, target;

        printf("Target = ");
        scanf("%d", &target);
        idx = recursiveBinarySearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target);

        if (idx == -1) {
            printf("Fail to Search\n");
        } else {
            printf("Target Index : %d\n", idx);
        }
        
    }

    return 0;

}
