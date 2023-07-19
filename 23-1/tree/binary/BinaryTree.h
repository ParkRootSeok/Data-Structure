#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct __btreenode {    // 이진 트리(노드 자체로 트리가 될 수 있으므로 노드도 트리도 모두 표현 가능)
    
    Data data;
    struct __node * left;
    struct __node * right;

} BTreeNode;

BTreeNode * MakeBTreeNode();    // 노드 생성

Data BGetData(BTreeNode * bt);  // 데이터 반환
void BSetData(BTreeNode * bt, Data data);   // 데이터 저장

BTreeNode * GetLeftSubTree(BTreeNode * bt);     // 왼쪽 서브 트리 주소 값 반환
BTreeNode * GetRightSubTree(BTreeNode * bt);    // 오른쪽 서브 트리 주소 값 반환


BTreeNode * MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);     // 왼쪽 서브 트리 연결
BTreeNode * MakeRightSubTree(BTreeNode * main, BTreeNode * sub);    // 오른쪽 서브 트리 연결

typedef void (*VisitFuncPtr)(Data data);    // 노드에 있는 데이터에 따라 출력을 구별하기 위해 함수 포인터 변수 이용

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);       // 중위 순회
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);      // 전위 순회
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);     // 후위 순회

#endif