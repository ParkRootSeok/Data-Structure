#ifndef __P_QUEUE_H__
#define __P_QUEUE_H__

#include "/Users/parkrootseok/Desktop/Programming/Git/Repository/Data_Structure/23-1/priority/heap/UHeap.h"

typedef Heap PQueue;

void PQueueInit(PQueue * pq, PriorityComp pc);
int PQIsEmpty(PQueue * pq);

void PEnqueue(PQueue * pq, Data d);
Data PDequeue(PQueue * pq);

#endif