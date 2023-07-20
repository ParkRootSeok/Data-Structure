#include <stdio.h>
#include "UHeap.h"

void HeapInit(Heap * h, PriorityComp pc) {

    h->numOfData = 0;
    h->comp = pc;

}

int HIsEmpty(Heap * h) {

    if (!h->numOfData) {
        return TRUE;
    }
    
    return FALSE;

}

int GetParentIdx(int idx) {

    return idx / 2;

}

int GetLeftChildIdx(int idx) {

    return idx * 2;
}

int GetRightChildIdx(int idx) {

    return GetLeftChildIdx(idx) + 1;
}

int GetPriChildIdx(Heap * h, int idx) {

    if (GetLeftChildIdx(idx) > h->numOfData) {  // 자식 노드가 존재하지 않으면
        return 0;
    } else if (GetLeftChildIdx(idx) == h->numOfData) {  // 자식 노드가 한 개라면
        return GetLeftChildIdx(idx);
    } else {    // 자식 노드가 두개라면
         
        if (h->comp(h->arr[GetLeftChildIdx(idx)], h->arr[GetRightChildIdx(idx)]) < 0) {
            return GetRightChildIdx(idx);
        } else {
            return GetLeftChildIdx(idx);
        }

    } 

}


void HInsert(Heap * h, Data d) {

    int idx = ++(h->numOfData);
    HeapElement newElem = {d};

    while (idx != 1) {
        if (h->comp(d, (h->arr[GetParentIdx(idx)])) > 0) {    // 부모 노드보다 우선 순위가 높다면

            h->arr[idx] = h->arr[GetParentIdx(idx)];    // 부모 노드 레벨 하락하고
            idx = GetParentIdx(idx);    // 새로운 노드가 저장될 인덱스는 레벨 상승
            
        } else  { // 아니라면 탈출
            break;
        }
        
    }

    h->arr[idx] = newElem;
    return;

}

Data HDelete(Heap * h) {

    Data removeData = h->arr[1].data;   // 삭제할 데이터 저장
    HeapElement lastElem = h->arr[h->numOfData];    // 마지막 노드 저장

    int childIdx, parentIdx = 1;
    
    /* 
        * 부모 노드 <= 마지막 노드 <= 자식 노드 관계를 만족하면 부모 노드에 마지막 노드를 삽입
        * 아니라면 부모 노드를 자식 노드로 갱신하여 다시 비교
        * 만족하는 노드가 하나도 없다면 자연스럽게 마지막 노드에 저장
    */
    while (childIdx = GetPriChildIdx(h, parentIdx)) {

        if (h->comp(lastElem.data, h->arr->data) >= 0) {
            break;
        }
        
        h->arr[parentIdx] = h->arr[childIdx];   
        parentIdx = childIdx;

    }
 
    h->arr[parentIdx] = lastElem;
    (h->numOfData)--;
    return removeData;

}

