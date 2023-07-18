#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CQueue.h"

#define CUSTOMER_COMMAND_TEAM 15

#define CHEEZE  0
#define BULGOGI 1
#define DOUBLE  2

#define CHEEZE_TEAM  12
#define BULGOGI_TEAM 15
#define DOUBLE_TEAM  24

int main() {

    int sec;
    int makeProc = 0;
    int cheezeOrder = 0, bulgogiOrder = 0, doubleOrder = 0;

    Queue q;

    QueueInit(&q);
    srand(time(NULL));

    for (sec = 0; sec < 3600; sec++) {  // 초가 계속 증가하면
        
        if (sec % CUSTOMER_COMMAND_TEAM == 0) { // 15초에 한번 씩 주문 실행
            
            int burger = rand() % 3;
            switch (burger) {
            case CHEEZE:
                Enqueue(&q, CHEEZE_TEAM);
                cheezeOrder++;
                break;

            case BULGOGI:
                Enqueue(&q, BULGOGI_TEAM);
                bulgogiOrder++;
                break;

            case DOUBLE:
                Enqueue(&q, DOUBLE_TEAM);
                doubleOrder++;
                break;

            }

        }

        if (makeProc <= 0 && !QIsEmpty(&q)) {   // 만드는 햄버거가 없고 큐에 대기가 있으면
            makeProc = dequeue(&q); // 다른 햄버거 제작 시작(대기실에서 나온다)
        }
    
        makeProc--; // 햄버거 제작
    
    }


}