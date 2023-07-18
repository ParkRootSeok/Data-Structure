#include <stdio.h>

/* 
  * 순차 탐색
  * 시간 복잡도 : T[n] = n (찾은 원소가 n-1번 째에 있을 경우 최악의 경우로 n번 실행)
  * 데이터 수 증가에 따라 연산횟수 증가가 비례
*/

int linearSearch(int * arr, int len, int target) {
    
    int cnt = 0;

    for (int i = 0; i < len; i++) {
        
        if (arr[i] == target) {
            return i; // 찾은 대상의 인덱스를 반환
        }

        cnt++;    
    } printf("연산 횟수 : %d\n", cnt);
    
    return -1;

}

int main(void) {

    int arr[] = {3, 5, 2, 4, 9};

    while (1) {
        
        int idx, target;

        printf("Target = ");
        scanf("%d", &target);
        idx = linearSearch(arr, sizeof(arr) / sizeof(int), target);

        if (idx == -1) {
            printf("Fail to Search\n");
        } else {
            printf("Target Index : %d\n", idx);
        }
        
    }

    return 0;
    
}