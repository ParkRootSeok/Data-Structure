#include <stdio.h>

void recursive(int num) {

    if (num <= 0) { // 재귀함수 탈출 조건
        return;
    }
    printf("Before recursive call! %d \n", num);
    recursive(num - 1);
    printf("After recursive call! %d \n", num);
    return;
}

int factorial(int num) {

    // num이 0인 경우 예외처리
    if (num < 1) {
        return 1;
    }   
    
    return factorial(num - 1) * num; 

}

int fibonacci(int num) {

    printf("func call param %d\n", num);

    // num이 음수가 나올 수 있는 조건들은 예외 처리
    if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;   
    }

    return fibonacci(num - 1) + fibonacci(num - 2);

}

int main() {

    // recursive(3);

    // for (int i = 1; i <= 10; i++) {
    //     // printf("%d! = %d \n", i, factorial(i)); 
    // }

    printf("fnbonacci(5) = %d \n", fibonacci(5)); 
    
}