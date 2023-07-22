#include <stdio.h>

int InterpolationSearch(int arr[], int first, int last, int target) {

    /*  이진 탐색과 다른 예외 처리 */
    // 인덱스와 찾는 값을 비례하여 찾기 때문에
    // 범위 안에 있는 숫자보다 작으면 계속 first는 작은 상태가
    // 크면 last는 계속 큰 상태가 지속
    if (arr[first] > target || arr[last] < target) {    
        return -1;
    }

    // 비례식에 의한 위치 설정
    int mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

    if (arr[mid] == target) {
        return mid;
    } else if (target < arr[mid]) {  // target이 왼쪽에 존재
        return InterpolationSearch(arr, first, mid - 1, target);
    } else {    // target이 오른쪽에 존재
        return InterpolationSearch(arr, mid + 1, last, target);
    }
    
}

int main() {

    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

    if (idx == -1) {
        printf("Fail To Search\n");
    } else {
        printf("Index : %d, value : %d\n", idx, arr[idx]);    
    }

    return 0;

}