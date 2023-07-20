#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE	1
#define FALSE	0
#define LENGTH	100

typedef char Data;
typedef int Prirority;

/* HEAP ADT */
typedef struct __heapelement {
    Prirority prirority;
    Data data;
} HeapElement;

typedef struct __heap {
    int numOfData;
    HeapElement arr[LENGTH];
} Heap;

void HeapInit(Heap * h);
int HIsEmpty(Heap * h);

void HInsert(Heap * h, Data d, Prirority p);
Data HDelete(Heap * h);

#endif