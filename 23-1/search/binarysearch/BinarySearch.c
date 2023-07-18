#include <stdio.h>

/*
  * 이진 탐색
  * 시간 복잡도 : T[n] = log2n
  * 이진 탐색은 반드시 원소 정렬이 필요
  * 데이터 수의 증가에 따라 연산 횟수의 증가는 미미
*/

int binarySearch(int* arr, int len, int target) {    

    int first = 0;
    int last = len - 1;
    int mid;
    int cnt = 0;

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
        cnt++;
    } printf("연산 횟수 : %d\n", cnt);

    return -1;

}

int main() {
    
    int arr[] = { 1, 2, 3, 7, 9, 12, 21, 23, 27};


    while (1) {
        
          
        int idx, target;

        printf("Target = ");
        scanf("%d", &target);
        idx = binarySearch(arr, sizeof(arr) / sizeof(int), target);

        if (idx == -1) {
            printf("Fail to Search\n");
        } else {
            printf("Target Index : %d\n", idx);
        }
        
    }

    return 0;

}
