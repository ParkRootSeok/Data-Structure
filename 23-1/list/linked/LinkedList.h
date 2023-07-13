#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

/* LinkedList ADT*/

typedef int Data;

typedef struct __node {
    Data data;
    Node * next;
} Node;

typedef struct __linkedList {    // 연결 기반 리스트 구조체 정의
    
    Node * head; // 더미 노드를 가리키는 노드
    Node * cur; // 참조 및 삭제를 위한 노드
    Node * before;  // 삭제를 위한 노드
    int numOfData; // 저장된 데이터 수
    int (*comp)(Data d1, Data d2);  // 정렬 기준 등록

} linkedList;

void listInit(linkedList * list);    
// 리스트 초기화

void LInsert(linkedList * list, Data data);   
// 데이터 저장

int LFirst(linkedList * list, Data * data);   
// 첫 번째 데이터 참조

int LNext(linkedList * list, Data * Data);    
// 두 번째 데이터 이후 참조

Data LDelete(linkedList * list);  
// 참조 데이터 삭제

int LCount(linkedList * list);    
// 데이터 수 반환 

void setSortRule(linkedList * list, int (*comp)(Data d1, Data d2));
// 리스트 정렬 기준 설정

#endif