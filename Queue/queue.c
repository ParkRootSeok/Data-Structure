#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)



typedef struct _node {

	int data;
	struct _node* next;

} Node;

typedef struct _queue { // Queue 구현(FIFO)

	Node * rear;	// 삽입 위치
	Node * front;	// 삭제 위치
	int size;		// 크기

} Queue;

void InitQueue(Queue* q);			// 큐 초기화
void enqueue(Queue* q, int data);	// 원소 삽입
int dequeue(Queue* q);				// 원소 삭제
int front(Queue* q);				// 첫 원소 반환
int size(Queue* q);					// 크기 반환
bool IsEmpty(Queue* q);				// 원소 여부 확인
void Elements(Queue* q);			// 모든 원소 보여주기

void main() {

	Queue q; InitQueue(&q);

	// 원소 삽입
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);

	// 원소 삭제
	printf("delete elem : %d\n", dequeue(&q));
	
	// 첫 원소 반환
	printf("front data : %d\n", front(&q));
	
	// 큐 사이즈 반환
	printf("Queue size : %d\n", size(&q));

	// 모든 원소 보기
	Elements(&q);

}

void InitQueue(Queue* q) {

	q->front = NULL;
	q->rear = NULL;
	q->size = 0;

}

void enqueue(Queue* q, int data) {

	// 추가할 노드 생성
	Node* new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	if (IsEmpty(q)) {
		q->front = new;
		q->rear = new;
	}
	else {
		q->rear->next = new;
		q->rear = new;
	}

	q->size++;

}

int dequeue(Queue* q) {
	Node* tmp = q->front;
	int re;

	if (IsEmpty(q)) {
		printf("Queue is Empty!!\n");
		return;
	}
	else {
		re = tmp->data;
		q->front = q->front->next;

		free(tmp);
		q->size--;
		return re;
	}
}

int front(Queue* q) {
	return q->front->data;
}

int size(Queue* q) {
	return q->size;
}

bool IsEmpty(Queue* q) {

	return (q->front == NULL && q->rear == NULL) ? true : false;

}

void Elements(Queue* q) {

	Node* tmp = q->front;
	while (tmp != NULL) {
		printf(" %d", tmp->data);
		tmp = tmp->next;
	} printf("\n");

}