#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct _node {

	int data;
	struct _node * next;

} Node;

typedef struct _stack {

	Node* top;
	int size;

} Stack;

void InitStack(Stack* stack);
void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsEmpty(Stack* stack);
void Elements(Stack * stack);


void main() {

	Stack stack; InitStack(&stack);

	Push(&stack, 1);
	Push(&stack, 2);
	Push(&stack, 3);
	Push(&stack, 4);
	Push(&stack, 5);
	printf("%d\n", Pop(&stack));
	Elements(&stack);

}

void InitStack(Stack* stack) {

	stack->top = NULL;
	stack->size = 0;
}

void Push(Stack* stack, int data) {

	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = stack->top;

	stack->top = new;
	stack->size++;

}

int Pop(Stack* stack) {

	Node* tmp;
	int re;

	if (IsEmpty(&stack)) {
		printf("Stack Is Empty!!\n");
		return;
	}
	else {
		tmp = stack->top;
		re = tmp->data;
		stack->top = stack->top->next;
		free(tmp);
	}

	return re;
}


bool IsEmpty(Stack* stack) {
	return stack->top == NULL ? true : false;
}

void Elements(Stack* stack) {

	Node * top = stack->top;

	if (IsEmpty(stack)) {
		printf("Stack Is Empty!!\n");
	}
	else {
		while (top != NULL) {
			printf(" %d", top->data);
			top = top->next;
		}
	}
}