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
	makeTree(&tree, 2, 4, 5);
	makeTree(&tree, 3, 6, 7);

	//printf("%d %d %d", tree.root->data, tree.root->left->data, tree.root->right->data);
	
	Node* root = tree.root;
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
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
	
	Node* pos = NULL;

	if (!tr->root) {
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

	printf("%d, %d, %d 트리 노드 생성 완료\n", pos->data, pos->left->data, pos->right->data );
}

void preOrder(Node* root) {

	if (root == NULL) return;

	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
	

}

void inOrder(Node* root) {

	if (root == NULL) return;

	preOrder(root->left);
	printf("%d ", root->data);
	preOrder(root->right);

}

void postOrder(Node* root) {

	if (root == NULL) return;

	preOrder(root->left);
	preOrder(root->right);
	printf("%d ", root->data);
	
}

