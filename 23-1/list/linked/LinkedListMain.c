#include <stdio.h>
#include "LinkedList.h"

/*
    * 연결 리스트
    * 동적 할당을 이용하여 정의된 구조체를 연결
    * 순차 리스트(배열 기반)과 달리 저장소의 크기 변경 가능
*/

int WhoIsPrecede(Data d1, Data d2) {

    if (d1 < d2) {
        return 0;
    } else {
        return 1;
    }
    
}

int main() {
    
    Data data;
    Data num;
    linkedList list;

    listInit(&list); // 리스트 초기화
    setSortRule(&list, WhoIsPrecede);

    while (1) { // 데이터 삽입

        printf("자연수 입력 : ");
        scanf("%d", &num);

        if(num == -1) break;

        LInsert(&list, num);

    }

    printf("number of Data = %d", LCount(&list)); // 저장된 데이터 갯수 출력 

   if(LFirst(&list, &data)) { // 데이터 출력
		
        printf("%d ", data);
		
		while(LNext(&list, &data)) {
            printf("%d ", data);
        }

	} printf("\n\n");

    if (LFirst(&list, &data)) {  // 1 데이터 모두 삭제

        if(data == 1) {
            LDelete(&list);
        }

		
		while(LNext(&list, &data)) {
			if(data == 1) {
				LDelete(&list);
            }
		}

	}

    printf("number of Data = %d", LCount(&list)); // 저장된 데이터 갯수 출력 

    if(LFirst(&list, &data)) { // 데이터 출력
		
        printf("%d ", data);
		
		while(LNext(&list, &data)) {
            printf("%d ", data);
        }

	} printf("\n\n");
    
    

}