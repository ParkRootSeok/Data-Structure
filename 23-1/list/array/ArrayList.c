#include <stdio.h>
#include "ArrayList.h"

void ListInit(ArrayList * list) {
	(list->numOfData) = 0;
	(list->curPosition) = -1;
}

void insert(ArrayList * list, Data data) {
    
    if (list->numOfData > LIST_LEN) {   // 저장 공간 부족 예외처리
        printf("Fail to insert\n");
    }
    

    (list->arr[list->numOfData]) = data;
    (list->numOfData)++;

}

int first(ArrayList * list, Data * data) {

    if (list->numOfData == 0) {
        return FALSE;
    }

    (list->curPosition) = 0; // 참조 위치 초기화
    *data = list->arr[0];

    return TRUE;

}

int next(ArrayList * list, Data * data) {

      if (list->curPosition >= (list->numOfData) - 1) { // 참조할 데이터 없음 예외 처리
        return FALSE;
    }

    // 현재 참조 위치의 다음을 메모리에 저장
    (list->curPosition)++;
    *data = list->arr[list->curPosition];

    return TRUE;

}

Data delete(ArrayList * list) {

    int deletePosition = list->curPosition;
    int num = list->numOfData;
    int i;
    
    // 삭제할 데이터 저장
    Data deleteData = list->arr[deletePosition];
    for (i = deletePosition; i < num - 1; i++) {
        // 데이터 삭제 (다음 데이터로 해당 데이터가 저장된 메모리를 초기화)
        list->arr[i] = list->arr[i+1];
    }
    
    (list->numOfData)--;    // 데이터 수 감소
    (list->curPosition)--;  // 참조 위치 되돌리기 (삭제 후 참조되지 않은 데이터를 참조하는 것을 방지)

    return deleteData;

}


int count(ArrayList * list) {

    return list->numOfData;

}