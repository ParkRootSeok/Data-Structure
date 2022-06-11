#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct _node {

	int data;
	struct _node* left;
	struct _node* right;

}Node;

typedef struct _tree {

	Node* root;
	int size;

} Tree;

void InitTree(Tree* tree);		// Ʈ�� �ʱ�ȭ
Node* new_node(int data);		// ��� ����

bool IsEmpty(Node * node);		// ������ ���� Ȯ��
bool IsInternal(Node * node);   // �ڽ� ��� O
bool IsExteranl(Node* node);	// �ڽ� ��� X

int size(Tree * tree);			// Ʈ�� ũ�� Ȯ��

Node* searchNode(Node* node, int data);					// ��� ã��
void makeTree(Tree* tr, int main, int letf, int right);		// Ʈ�� ����



void main() {

	Tree tree; InitTree(&tree);

}

void InitTree(Tree* tree) {

	tree->root = NULL;
	tree->size = 0;

}

Node* new_node(int data) {

	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->left = new->right = NULL;

	return new;
}

bool IsEmpty(Node* node) {

	return node == NULL ? true : false;

}

bool IsInternal(Node* node) {

	return (node->left != NULL || node->right != NULL)? true : false;

}

bool IsExteranl(Node* node) {
	return (node->left == NULL && node->right == NULL)? true : false;
}

int size(Tree * tree){
	return tree->size;
}

Node* searchNode(Node* node, int data) {

	Node* tmp;

	if (node->data == data) {
		return node;
	}
	
	if (IsInternal(node)) {
		if (node->left) {
			tmp = searchNode(node->left, data);
		}
		else if (node -> right) {
			tmp = searchNode(node->right, data);
		}
	}

	return tmp;

}

void makeTree(Tree* tr, int main, int letf, int right) {

	Node* pos;

	if (IsEmpty(tr->root)) {
		pos = new_node(main);
		tr->root = pos;
		tr->size++;
	}
	else pos = searchNode(tr->root, main);

	if (letf) {

		pos->left = new_node(letf);
		tr->size++;
	}
	
	if (right) {
		pos->right = new_node(right);
		tr->size++;
	}


}