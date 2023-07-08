#include <stdio.h>

/*
  * 이진 탐색
  * 시간 복잡도 : 
  * 이진 탐색은 반드시 원소 정렬이 필요
*/
int binarySearch(int* arr, int len, int target) {    

    int first = 0;
    int last = len - 1;
    int mid;

    while (first <= last) {
        
        mid = (first + last) / 2;

        if (arr[mid] == target) {
            return mid;
        } else {
            
            if (arr[mid] > target) { 
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
         
    }
    
    return -1;

}

int main() {
    
    int arr[] = { 1, 2, 3, 7, 9, 12, 21, 23, 27};


    while (1) {
        
          
        int idx, target;

        printf("target = ");
        scanf("%d", &target);
        idx = binarySearch(arr, sizeof(arr) / sizeof(int), target);

        if (idx == -1) {
            printf("Fail to Search\n");
        } else {
            printf("Target index : %d\n", idx);
        }
        
    }

    return 0;

}
