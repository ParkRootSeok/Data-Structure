#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int idx1, int idx2) {

    int tmp;

    tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;

}

int Partition(int arr[], int left, int right) {

    int pivot = arr[left];
    int low = left + 1, high = right;

    while (low <= high) {
        
        while (pivot >= arr[low] && low <= right) {  // pivot보다 작으면 이동
           low++;
        }
        
        while (pivot <= arr[high] && high >= (left + 1)) { // pivot보다 크면 이동
           high--;
        }

        if (low <= high) {          // 교차하지 않았으면 교환
            Swap(arr, low, high);
        }
        
    }

    // 교차를 했다면 arr[high] <  arr[left] = pivot < arr[low] 가 성립
    // pivot을 arr[high]와 스왑하여 정렬
    Swap(arr, left, high);
    return high;
    
}

void QuickSort(int arr[], int left, int right) {

    if (left > right) {
        return;
    }

    int pivot = Partition(arr, left, right);
    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
    
}



int main() {

    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int len = sizeof(arr) / sizeof(int);
    QuickSort(arr, 0, len - 1);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}