#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)



typedef struct _node {

	int data;
	struct _node* next;

} Node;

typedef struct _queue { // Queue ����(FIFO)

	Node * rear;	// ���� ��ġ
	Node * front;	// ���� ��ġ
	int size;		// ũ��

} Queue;

void InitQueue(Queue* q);			// ť �ʱ�ȭ
void enqueue(Queue* q, int data);	// ���� ����
int dequeue(Queue* q);				// ���� ����
int front(Queue* q);				// ù ���� ��ȯ
int size(Queue* q);					// ũ�� ��ȯ
bool IsEmpty(Queue* q);				// ���� ���� Ȯ��
void Elements(Queue* q);			// ��� ���� �����ֱ�

void main() {

	Queue q; InitQueue(&q);

	// ���� ����
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);

	// ���� ����
	printf("delete elem : %d\n", dequeue(&q));
	
	// ù ���� ��ȯ
	printf("front data : %d\n", front(&q));
	
	// ť ������ ��ȯ
	printf("Queue size : %d\n", size(&q));

	// ��� ���� ����
	Elements(&q);

}

void InitQueue(Queue* q) {

	q->front = NULL;
	q->rear = NULL;
	q->size = 0;

}

void enqueue(Queue* q, int data) {

	// �߰��� ��� ����
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