#include <stdio.h>
#include "/Users/parkrootseok/Desktop/Programming/Git/Repository/Data_Structure/23-1/priority/heap/UHeap.h"
#include "PQueue.h"

void PQueueInit(PQueue * pq, PriorityComp pc) {

    HeapInit(pq,pc);

}

int PQIsEmpty(PQueue * pq) {
    HIsEmpty(pq);
}

void PEnqueue(PQueue * pq, Data d) {

    HInsert(pq, d);

}

Data PDequeue(PQueue * pq) {

    HDelete(pq);

}
