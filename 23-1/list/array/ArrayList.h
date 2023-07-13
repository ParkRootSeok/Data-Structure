#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/* ArrayList ADT*/
#define LIST_LEN	100

typedef int Data;

typedef struct __ArrayList {    // 배열 기반 리스트 구조체 정의
    
    Data arr[LIST_LEN]; // 저장소
    int numOfData;  // 데이터 수
    int curPosition;    // 현재 참조중인 위치

} ArrayList;

void listInit(ArrayList * list);    // 리스트 초기화
void insert(ArrayList * list, Data data);   // 데이터 저장
int first(ArrayList * list, Data * data);   // 첫 번째 데이터 참조
int next(ArrayList * list, Data * Data);    // 두 번째 데이터 이후 참조
Data delete(ArrayList * list);  // 참조 데이터 삭제
int count(ArrayList * list);    // 데이터 수 반환 

#endif