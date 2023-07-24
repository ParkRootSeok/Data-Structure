#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode() {

    BTreeNode * newNode = (BTreeNode *)malloc(sizeof(BTreeNode));

    newNode->left = newNode->right = NULL;
    return newNode;

}

Data BGetData(BTreeNode * bt) {

    return bt->data;

}
void BSetData(BTreeNode * bt, Data data) {

    bt->data = data;

}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
    return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt) {
    return bt->right;
}

BTreeNode * MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {

    if(main->left != NULL) {
        free(main->left);
    }

    main->left = sub;

}
BTreeNode * MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {

    if(main->right != NULL) {
        free(main->right);
    }

    main->right = sub;
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action) {

    if (bt == NULL) {
        return ;
    }

    InorderTraverse(bt->left, action);  // 왼쪽 서브 트리
    action(bt->data); // 루트 노드
    InorderTraverse(bt->right, action); // 오른쪽 서브 트리

}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action) {

    if (bt == NULL) {
        return ;
    }

    action(bt->data); // 루트 노드
    PreorderTraverse(bt->left, action);  // 왼쪽 서브 트리 
    PreorderTraverse(bt->right, action); // 오른쪽 서브 트리

}
  
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action) { 

    if (bt == NULL) {
        return ;
    }

    PostorderTraverse(bt->right, action); // 오른쪽 서브 트리
    action(bt->data);  // 루트 노드
    PostorderTraverse(bt->left, action);  // 왼쪽 서브 트리

}