#include <stdio.h>
#include "DBLinkedList.h"

void listInit(doubleLinkedList * list) {

    list->head = NULL; 
    list->numOfData = 0;

}

void LInsert(doubleLinkedList * list, Data data) {

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = list->head; // 새로운 노드 -> 기존 노드
    if (list->head != NULL) {   // 기존 노드가 존재하면
        list->head->prev = newNode; // 기존 노드 -> 새로운 노드
    }
    
    newNode->prev = NULL;   // NULL <- 새로운 노드
    list->head = newNode;   // head 새로운 노드로 변경

    (list->numOfData)++;
    
}

int LFirst(doubleLinkedList * list, Data * data) {

    if (list->head == NULL) {
        return FALSE;
    }
    
    /*
        * list->before = list->head; 
        * 이전 노드를 갱신할 필요가 없음
    */
    list->cur = list->head;   // cur -> first node
    *data = list->cur->data;
    
    return TRUE;

}

int LNext(doubleLinkedList * list, Data * data) {

    if (list->head == NULL) {
        return FALSE;
    }

    /*
        * list->before = list->cur;   
        * 이전 노드를 갱신할 필요가 없음
    */
    list->cur = list->cur->next;    // cur -> 현재 참조 노드의 다음 노드
    *data = list->cur->data;

    return TRUE;

}

int LPrevious(doubleLinkedList * list, Data * data) {

    if (list->head == NULL) {
        return FALSE;
    } 

    list->cur = list->cur->prev;    // LNext 메소드와 진행 방향만 다름
    *data = list->cur->data;

    return TRUE;

}



int LCount(doubleLinkedList * list) {

    return list->numOfData;

}