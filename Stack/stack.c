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


void main() {

}