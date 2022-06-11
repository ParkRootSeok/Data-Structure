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

void InitTree(Tree* tree);		// 트리 초기화
Node* new_node(int data);		// 노드 생성

bool IsEmpty(Node * node);		// 데이터 여부 확인
bool IsInternal(Node * node);   // 자식 노드 O
bool IsExteranl(Node* node);	// 자식 노드 X

int size(Tree * tree);			// 트리 크기 확인

Node* searchNode(Node* node, int data);					// 노드 찾기
void makeTree(Tree* tr, int main, int letf, int right);		// 트리 생성

void preOrder(Tree* tree);		// 선위 순회 (root -> L -> R)
void inOrder(Tree* tree);		// 중위 순회 (L -> root -> R)
void postOrder(Tree* tree);		// 후위 순회 (L -> R > root)

void main() {

	Tree tree; InitTree(&tree);
	makeTree(&tree, 1, 2, 3);
	//makeTree(&tree, 2, 4, 5);
	//makeTree(&tree, 3, 6, 7);

	printf("%d %d %d", tree.root->data, tree.root->left->data, tree.root->right->data);
	//printf("%d %d %d", root->left->data, root->left->left->data, root->left->right->data);
	//printf("%d %d %d", root->right->data, root->right->left->data, root->right->right->data);

	/*
	preOrder(&tree);
	inOrder(&tree);
	postOrder(&tree);
	*/
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

	return node->left || node->right? true : false;

}

bool IsExteranl(Node* node) {
	return (node->left == NULL && node->right == NULL)? true : false;
}

int size(Tree * tree){
	return tree->size;
}

Node* searchNode(Node* node, int data) {

	Node* tmp = NULL;

	if (node->data == data) {
		return node;
	}
	
	if (IsInternal(node)) {

		if (node->left && !tmp) {
			tmp = searchNode(node->left, data);
		}

		if (node -> right && !tmp) {
			tmp = searchNode(node->right, data);
		}
	}

	return tmp;

}

void makeTree(Tree* tr, int main, int letf, int right) {
	Node* root = tr->root;
	Node* pos = NULL;

	if (!root) {
		pos = new_node(main);
		root = pos;
		tr->size++;
	}
	else pos = searchNode(root, main);

	if (letf) {
		pos->left = new_node(letf);
		tr->size++;
	}
	
	if (right) {
		pos->right = new_node(right);
		tr->size++;
	}

	printf("%d, %d, %d 트리 노드 생성 완료\n", root->data, root->left->data, root->right->data );
}

void preOrder(Tree* tree) {

	if (IsEmpty(tree->root)) return;

	printf("%d ", tree->root->data);
	preOrder(tree->root->left);
	preOrder(tree->root->right);
	

}

void inOrder(Tree* tree) {

	if (IsEmpty(tree->root)) return;

	preOrder(tree->root->left);
	printf("%d ", tree->root->data);
	preOrder(tree->root->right);

}

void postOrder(Tree* tree) {

	if (IsEmpty(tree->root)) return;

	preOrder(tree->root->left);
	preOrder(tree->root->right);
	printf("%d ", tree->root->data);
	
}
