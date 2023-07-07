#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct _node {

	int data;
	struct _node* prev;
	struct _node* next;

} Node ;

typedef struct _deque { // ��ũ ����(���԰� ������ ��� ���⿡�� ����)

	Node* rear;
	Node* front;
	int size;

} Deque;

void InitDeque(Deque* dq);					// ť �ʱ�ȭ
void insertFront(Deque* dq, int data);		// ���� ����(front)
int deleteFront(Deque* dq);					// ���� ����(front)
void insertRear(Deque* dq, int data);		// ���� ����(rear)
int deleteRear(Deque* dq);					// ���� ����(rear)
int front(Deque* dq);						// front ��ġ ���� ��ȯ
int rear(Deque* dq);						// rear ��ġ ���� ��ȯ
int size(Deque* dq);						// ũ�� ��ȯ
bool IsEmpty(Deque* dq);					// ���� ���� Ȯ��

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

	// ���� ����
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

	// ���� ����
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
