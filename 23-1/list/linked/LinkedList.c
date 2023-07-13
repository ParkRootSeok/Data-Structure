#include <stdio.h>
#include "LinkedList.h"

void listInit(linkedList * list) {

	list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL; 
    list->cur = NULL;
    list->numOfData = 0;

}

void FInsert(linkedList * list, Data data) {
    
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    
    /* 더미 노드와 기존 노드사이에 새로운 노드를 연결하는 과정 */
    newNode->next = list->head->next; // 새로운 노드를 더미 노드가 가리키는 노드와 연결
    list->head->next = newNode; // 더미 노드를 새로운 노드와 연결

    (list->numOfData)++;

}

void SInsert(linkedList * list, Data data) {

    Node * newNode = (Node *)malloc(sizeof(Node));
    Node * pred = list->head;   // pred -> 더미 노드

    newNode->data = data;

    /* 새로운 노드가 들어갈 위치 찾기
        * comp는 후자보다 작으면 0, 크면 1 을 반환하는 함수
        * 현재는 오름차순 정렬이나 comp 함수를 수정하여 내림차순으로 수정 가능
    */
    while (pred->next != NULL && list->comp(data, pred->next->data) != 0) { // 다음 노드가 존재하고 data가 다음 노드의 데이터보다 작으면(다음 데이터보다 숫자가 작으면)
        pred = pred->next;  // 다음 노드 이동
    }

    newNode->next = pred->next;
    pred->next = newNode;
    
    (list->numOfData)++;

}


void LInsert(linkedList * list, Data data) {
    
    if (list->comp == NULL) { 
        FInsert(list, data);
    } else {
        SInsert(list, data);
    }

}

int LFirst(linkedList * list, Data * data) {

    if (list->head->next == NULL) {
        return FALSE;
    }
    
    list->before = list->head; // before -> dummy node
    list->cur = list->head->next;   // cur -> first node
    
    *data = list->cur->data;
    
    return TRUE;

}

int LNext(linkedList * list, Data * data) {

    if (list->cur->next == NULL) {
        return FALSE;
    }

    list->before = list->cur;   // before -> 현재 참조중인 노드
    list->cur = list->cur->next;    // cur -> 현재 참조 노드의 다음 노드
    
    *data = list->cur->data;

    return TRUE;

}

Data LDelete(linkedList * list) {

    if (list->head->next == NULL) {
        printf("저장된 데이터가 없습니다.\n");
        return -1;
    }

    Node * removeNode = list->cur;
    Data removeData = removeNode->data;

    list->before->next = list->cur->next;
    list->cur = list->before;   // 중요!! 삭제 후 꼭 참조 위치를 변경

    free(removeNode);
    (list->numOfData)--;
    return removeData;

}


int LCount(linkedList * list) {

    return list->numOfData;

}

void setSortRule(linkedList * list, int (*comp)(Data d1, Data d2)) {

    list->comp = comp;

}