#include <stdio.h>
#include "DBLinkedList.h"

/*
    * 양방향 연결 리스트
    * 단순 연결 리스트와 달리 노드에 이전과 다음 노드에 대한 정보 포함
*/


int main() {
    
    int i;
    Data data;
    Data num;
    doubleLinkedList list;

    listInit(&list); // 리스트 초기화

    while (1) { // 데이터 삽입

        printf("자연수 입력 : ");
        scanf("%d", &num);

        if(num == -1) break;

        LInsert(&list, num);

    } printf("number of Data = %d", LCount(&list)); // 데이터 갯수 조회

   if(LFirst(&list, &data)) { // 데이터 조회
		
        printf("%d ", data);
		
		while (LNext(&list, &data)) {
                printf("%d ", data);
        } printf("\n");
        
        while (LPrevious(&list, &data)) {
                printf("%d ", data);
        }

	} printf("\n\n");

}