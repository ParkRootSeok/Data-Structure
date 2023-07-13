#include <stdio.h>

/*
    * 하노이 타워
    * num개의 원반을 by를 거쳐서 from에서 to로 이동
    * 해결 알고리즘
    * 1. n-1개의 작은 원반을 A->B
    * 2. n번째 큰 원반을 A->C
    * 3. n-1개의 작은 원반을 B->C
*/
void move(int num, char from, char by, char to) {
    
    if (num == 1) {
        printf("%d번째 원반을 %c에서 %c로 이동\n", num, from, to);
        return;
    } else {
        // 1단계
        move(num - 1, from, to, by);

        // 2단계
        printf("%d번째 원반을 %c에서 %c로 이동\n", num, from, to);

        // 3단계
        move(num - 1, by, from, to);        
    }


}

int main() {
    move(3, 'A', 'B', 'C');
    return 0;
}