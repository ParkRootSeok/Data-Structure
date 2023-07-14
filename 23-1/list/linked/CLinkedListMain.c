#include <stdio.h>
#include "CLinkedList.h"

/*
    * 원형 연결 리스트
    * 단술 연결 리스트와 달리 head, tail 모두 노드 추가 가능
    * tail 노드가 head(tail->next)/tail 두 가지 역할을 담당
*/


int main() {
    
    int i;
    Data data;
    Data num;
    ClinkedList list;

    listInit(&list); // 리스트 초기화

    while (1) { // 데이터 삽입

        printf("자연수 입력 : ");
        scanf("%d", &num);

        if(num == -1) break;

        LInsert(&list, num);

    } printf("number of Data = %d", LCount(&list)); // 데이터 갯수 출력 

   if(LFirst(&list, &data)) { // 데이터 출력
		
        printf("%d ", data);
		
		for (i = 0; i < LCount(&list) - 1; i++) {
            LNext(&list, &data);
            printf("%d ", data);
        }
        

	} printf("\n\n");

    if (LFirst(&list, &data)) {  // 데이터 삭제

        if(data % 2 == 0) {
            LDelete(&list);
        }
			
		for (i = 0; i < LCount(&list) - 1; i++) {
            LNext(&list, &data);
            if(data % 2 == 0) {
                LDelete(&list);
            }

        }

	}

    printf("number of Data = %d", LCount(&list)); // 데이터 갯수 출력 

    if(LFirst(&list, &data)) { // 데이터 출력
		
        printf("%d ", data);
		
        for (i = 0; i < LCount(&list) - 1; i++) {
            LNext(&list, &data);
            printf("%d ", data);
        }

	} printf("\n\n");
    
    

}