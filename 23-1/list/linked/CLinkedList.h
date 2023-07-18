#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

/* Circular LinkedList ADT*/

typedef int Data;

typedef struct __node {
    Data data;
    struct __node * next;
} Node;

typedef struct __ClinkedList {    // 연결 기반 리스트 구조체 정의
    
    Node * tail; // 더미 노드를 가리키는 노드
    Node * cur; // 참조 및 삭제를 위한 노드
    Node * before;  // 삭제를 위한 노드
    int numOfData; // 저장된 데이터 수

} ClinkedList;

void listInit(ClinkedList * list);    
// 리스트 초기화

void LInsert(ClinkedList * list, Data data);   
// 데이터 저장(tail)

void LInsertFront(ClinkedList * list, Data data);   
// 데이터 저장(head)

int LFirst(ClinkedList * list, Data * data);   
// 첫 번째 데이터 참조

int LNext(ClinkedList * list, Data * Data);    
// 두 번째 데이터 이후 참조

Data LDelete(ClinkedList * list);  
// 참조 데이터 삭제

int LCount(ClinkedList * list);    
// 데이터 수 반환 

#endif