#include <stdio.h>
#include <stdlib.h>
#include "PointList.h"

int main() {

    PointList list;
	Point * data;
	
    // 리스트 초기화
    listInit(&list);

    // 데이터 저장
	data = (Point *)malloc(sizeof(Point));	setPoint(data, 2, 1);	insert(&list, data);
	data = (Point *)malloc(sizeof(Point));	setPoint(data, 2, 2);	insert(&list, data);
	data = (Point *)malloc(sizeof(Point));	setPoint(data, 3, 1);	insert(&list, data);
	data = (Point *)malloc(sizeof(Point));	setPoint(data, 3, 2);	insert(&list, data);

    // 저장된 데이터 갯수 출력
    printf("number of Data = %d", count(&list));

    if(first(&list, &data)) { // 데이터 출력
		
        showPointInfo(data);
		
		while(next(&list, &data)) {
            showPointInfo(data);
        }

	}
	printf("\n\n");

	Point cPoint;
	cPoint.x = 2; cPoint.y = 0;
    if (first(&list, &data)) {  // x가 같은 Position 삭제

		if(comparePoint(data, &cPoint) == 1) {
		
			data = delete(&list);
			free(data);	// 할당된 메모리를 해제(이 과정은 리스트에서 수행하는 것이 아님)
		
		}

		while(next(&list, &data)) {
			
			if(comparePoint(data, &cPoint) == 1) {
				data = delete(&list);
				free(data);
			}

		}

	}

    // 저장된 데이터 갯수 출력
    printf("number of Data = %d", count(&list));

	if(first(&list, &data)) {   // 삭제 후 데이터 출력

		showPointInfo(data);
		
		while(next(&list, &data)) {
            showPointInfo(data);
        }

    }
	printf("\n\n");

	return 0;

}

