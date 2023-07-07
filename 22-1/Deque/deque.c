#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct _node {

	int data;
	struct _node* prev;
	struct _node* next;

} Node ;

typedef struct _deque { // 데크 구현(삽입과 삭제는 모든 방향에서 가능)

	Node* rear;
	Node* front;
	int size;

} Deque;

void InitDeque(Deque* dq);					// 큐 초기화
void insertFront(Deque* dq, int data);		// 원소 삽입(front)
int deleteFront(Deque* dq);					// 원소 삭제(front)
void insertRear(Deque* dq, int data);		// 원소 삽입(rear)
int deleteRear(Deque* dq);					// 원소 삭제(rear)
int front(Deque* dq);						// front 위치 원소 반환
int rear(Deque* dq);						// rear 위치 원소 반환
int size(Deque* dq);						// 크기 반환
bool IsEmpty(Deque* dq);					// 원소 여부 확인

void main() {

	Deque dq; InitDeque(&dq);

	insertFront(&dq, 1);
	insertRear(&dq, 2);
	insertFront(&dq, 3);
	insertRear(&dq, 4);
	insertFront(&dq, 5);
	insertRear(&dq, 6);
	frontElements(&dq);

	printf("delete front : %d\n", deleteFront(&dq));
	printf("delete Rear : %d\n", deleteRear(&dq));
	printf("front elem : %d\n", front(&dq));
	printf("rear elem : %d\n", rear(&dq));
	printf("Deque Size : %d\n", size(&dq));

}

void InitDeque(Deque* dq) {

	dq->front = NULL;
	dq->rear = NULL;
	dq->size = 0;

}

void insertFront(Deque* dq, int data) {	

	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data; new->next = NULL; new->prev = NULL;

	if (dq->front == NULL) {
		dq->front = dq->rear = new;
	}


	new->next = dq->front;
	dq->front->prev = new;
	dq->front = new;

	new->prev = NULL;
	
	dq->size++;

}

int deleteFront(Deque* dq) {
	
	Node* tmp = dq->front; 
	int re;

	if (IsEmpty(dq)) {
		printf("Deque is Empty!!\n"); return;
	}

	// 원소 저장
	re = tmp->data;
	
	dq->front = dq->front->next;
	dq->front->prev = NULL;

	if (dq->front == NULL) dq->front = dq->rear = NULL;
	
	free(tmp);
	dq->size--;

	return re;

}
void insertRear(Deque* dq, int data) {

	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data; new->next = NULL; new->prev = NULL;

	if (dq->rear == NULL) {
		dq->front = dq->rear = new;
	}

	dq->rear->next = new;
	new->prev = dq->rear;
	dq->rear = new;

	new->next = NULL;
	dq->size++;

}

int deleteRear(Deque* dq) {

	Node* tmp = dq->rear;
	int re;

	if (IsEmpty(dq)) {
		printf("Deque is Empty!!\n"); return;
	}

	// 원소 저장
	re = tmp->data;

	dq->rear = dq->rear->prev;
	dq->front->next = NULL;

	if (dq->rear == NULL) dq->front = dq->rear = NULL;

	free(tmp);
	dq->size--;

	return re;
}
int front(Deque* dq) {

	return dq->front->data;

}

int rear(Deque* dq) {

	return dq->rear->data;

}

int size(Deque* dq) {

	return dq->size;
}

bool IsEmpty(Deque* dq) {
	return dq->front == NULL && dq->rear == NULL ? true : false;
}
