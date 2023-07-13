#include <stdio.h>
#include "ArrayList.h"

int main() {

    ArrayList list;
	Data data;
	
    // 리스트 초기화
    listInit(&list);

    // 데이터 저장
    insert(&list, 11);  insert(&list, 11);
	insert(&list, 22);  insert(&list, 22);
	insert(&list, 33);

    // 저장된 데이터 갯수 출력
    printf("number of Data = %d", count(&list));

    if(first(&list, &data)) {
		
        printf("%d ", data);
		
		while(next(&list, &data)) {
            printf("%d ", data);
        }

	}
	printf("\n\n");

    if (first(&list, &data)) {  // 22 데이터 모두 삭제

		if(data == 22) 
			delete(&list);
		
		while(next(&list, &data)) {
			if(data == 22)
				delete(&list);
		}

	}

    // 저장된 데이터 갯수 출력
    printf("number of Data = %d", count(&list));

	if(first(&list, &data)) {   // 삭제 후 데이터 출력

		printf("%d ", data);
		
		while(next(&list, &data)) {
            printf("%d ", data);
        }

    }
	printf("\n\n");

	return 0;

}

