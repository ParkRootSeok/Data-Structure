#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

/* Doubly LinkedList ADT*/

typedef int Data;

typedef struct __node {
    Data data;
    struct __node * next;   // 다음 노드
    struct __node * prev;   // 이전 노드 (양방향 연결 리스트인 이유)
} Node;

typedef struct __doubleLinkedList {    // 연결 기반 리스트 구조체 정의
    
    Node * head; // 더미 노드를 가리키는 노드
    Node * cur; // 참조 및 삭제를 위한 노드
    int numOfData; // 저장된 데이터 수

} doubleLinkedList;

void listInit(doubleLinkedList * list);    
// 리스트 초기화

void LInsert(doubleLinkedList * list, Data data);   
// 데이터 저장

void LInsertFront(doubleLinkedList * list, Data data);   
// 데이터 저장

int LFirst(doubleLinkedList * list, Data * data);   
// 첫 번째 데이터 참조

int LNext(doubleLinkedList * list, Data * data);    
// 우측 노드 참조

int LPrevious(doubleLinkedList * list, Data * data);  
// 좌측 노드 참조

int LCount(doubleLinkedList * list);    
// 데이터 수 반환 

#endif