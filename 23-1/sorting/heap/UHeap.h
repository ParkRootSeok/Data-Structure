#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE	1
#define FALSE	0
#define LENGTH	100

typedef char Data;
typedef int (*PriorityComp)(Data d1, Data d2);

/* UPGRADE HEAP ADT */
typedef struct __heapelement {
    Data data;
} HeapElement;

typedef struct __heap {

    PriorityComp * comp;
    int numOfData;
    HeapElement arr[LENGTH];
} Heap;

void HeapInit(Heap * h, PriorityComp pc);
int HIsEmpty(Heap * h);

void HInsert(Heap * h, Data d);
Data HDelete(Heap * h);

#endif