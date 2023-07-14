#include <stdio.h>
#include "ClinkedList.h"

void listInit(ClinkedList * list) {

	list->tail = (Node *)malloc(sizeof(Node));
    list->tail->next = NULL; 
    list->cur = NULL;
    list->numOfData = 0;

}

void LInsertBack(ClinkedList * list, Data data) {
    
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

   if (list->tail->next == NULL) {
        list->tail = newNode;
        list->tail->next = newNode;
   } else { 
        newNode->next = list->tail->next;   // 생성한 노드 -> 첫 번째 노드
        list->tail->next = newNode;         // 기존 마지막 노드 -> 생성한 노드
        list->tail = newNode;               // 새로운 노드를 tail로 설정
   }
   
     (list->numOfData)++;

}

void LInsertFront(ClinkedList * list, Data data) {

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

     if (list->tail == NULL) { 
        list->tail = newNode;
        list->tail->next = newNode;
        
    } else {
        newNode->next = list->tail->next;   // 생성한 노드 -> 기존 첫 번째 노드
        list->tail->next = newNode;         // tail -> 생성한 노드
    }

    (list->numOfData)++;
    
}

int LFirst(ClinkedList * list, Data * data) {

    if (list->tail == NULL) {
        return FALSE;
    }
    
    list->before = list->tail; // before -> dummy node
    list->cur = list->tail->next;   // cur -> first node
    
    *data = list->cur->data;
    
    return TRUE;

}

int LNext(ClinkedList * list, Data * data) {

    if (list->tail == NULL) {
        return FALSE;
    }

    list->before = list->cur;   // before -> 현재 참조중인 노드
    list->cur = list->cur->next;    // cur -> 현재 참조 노드의 다음 노드
    
    *data = list->cur->data;

    return TRUE;

}

Data LDelete(ClinkedList * list) {

    if (list->tail == NULL) {
        printf("저장된 데이터가 없습니다.\n");
        return -1;
    }

    Node * removeNode = list->cur;
    Data removeData = removeNode->data;
    
    if (removeNode == list->tail) { // 삭제 노드가 tail 이면서
        
        if (list->tail == list->tail->next) { // 마지막 노드이면
            list->tail = NULL; // tail NULL로 초기화
        } else {
            list->tail = list->before; // tail 변경
        }
    }

    list->before->next = list->cur->next;
    list->cur = list->before;   

    free(removeNode);
    (list->numOfData)--;
    return removeData;

}


int LCount(ClinkedList * list) {

    return list->numOfData;

}