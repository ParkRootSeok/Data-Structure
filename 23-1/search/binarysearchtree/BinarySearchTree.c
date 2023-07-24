#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "BinarySearchTree.h"

/* Binary Search Tree ADT */

void BSTreeInit(BTreeNode ** bst) {

    *bst = NULL;

}

Data BSTGetData(BTreeNode * bst) {

    return BGetData(bst);

}

void BSTInsert(BTreeNode ** bst, Data data) {

    BTreeNode * pNode = NULL;
    BTreeNode * cNode = *bst;
    BTreeNode * nNode = NULL;

    // 새로운 노드가 들어갈 위치 탐색
    while (cNode != NULL) {
        
        if(data == BGetData(cNode)) {    // 중복 데이터는 예외 처리
            return;
        }

        pNode = cNode;

        if(data < BGetData(cNode)) {    // 부모 노드의 데이터보다 작으면 좌측 
            cNode = GetLeftSubTree(cNode);
        } else { // 크면 우측
            cNode = GetRightSubTree(cNode);
        }

    }

    nNode = MakeBTreeNode();
    BSetData(nNode, data);

    if (pNode != NULL) {    // 루트 노드가 아니면 
        if(data < BGetData(pNode)) {    // 작으면 좌측에 저장
            MakeLeftSubTree(pNode, nNode);  
        } else {    // 크다면 우측에 저장
            MakeRightSubTree(pNode, nNode);
        }
    } else {    // 루트 노드이면 루트 노드로 할당
        *bst = nNode;
    }

}

BTreeNode * BSTDelete(BTreeNode ** bst, Data target) {
    
    BTreeNode * vNode = MakeBTreeNode;
    BTreeNode * pNode = vNode;
    BTreeNode * cNode = *bst;
    BTreeNode * dNode;

    ChangeRightSubTree(vNode, *bst);
    
    while (cNode != NULL && BGetData(cNode) != target) {
        
        pNode = cNode;

        if (target < BGetData(cNode)) {
            cNode = GetLeftSubTree(cNode);
        } else {
           cNode = GetRightSubTree(cNode);
        }

        if (cNode == NULL) {
            return NULL;
        }

        dNode = cNode;

        /*
            * 단말 노드인 경우
         */
        if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)   {

            // 해당 노드를 검색하여 삭제
            if (GetLeftSubTree(pNode) == dNode) { 
                RemoveLeftSubTree(pNode);
            } else {
                RemoveRightSubTree(pNode);    
            }
            
        }

        /*
            * 하나의 자식 노드를 가지는 경우
         */
        else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {

            BTreeNode * cdNode;

            // 좌,우 서브 노드 탐색
            if (GetLeftSubTree(dNode) != NULL) {    
                cdNode = GetLeftSubTree(dNode);
            } else {
                cdNode = GetRightSubTree(dNode);
            }
            
            // 위에서 탐색한 노드를 삭제할 노드와 교체
            if (GetLeftSubTree(pNode) == dNode) {   // 좌측 서브 노드일 때
                ChangeLeftSubTree(pNode, cdNode);
            } else {    // 우측 서브 노드일 때
                ChangeRightSubTree(pNode, cdNode);    
            }
            
        } 

        /*
            * 두 개의 자식 노드를 가지는 경우
         */
        else {

            BTreeNode * mNode = GetRightSubTree(dNode); // 대체 노드 (대체 노드는 가장 작은 값을 지리는 오른쪽 노드!)
            BTreeNode * mpNode = dNode;                 // 대체 노드의 부모 노드
            Data delData;

            while (GetLeftSubTree(mNode) != NULL) { // 대체 노드 탐색
                mpNode = mNode;
                mNode = GetLeftSubTree(mNode);
            }
            
            delData = BGetData(dNode);
            BSetData(dNode, BGetData(mNode));   // 삭제 노드 값 변경

            // 부모 노드와 대체 노드의 자식과 연결
            if(GetLeftSubTree(mpNode) == mNode){    
                ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
            } else {
                ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
            }

            dNode = mNode;
            BSetData(dNode, delData);
        }

        if (GetRightSubTree(vNode) != *bst) {   // 삭제된 노드가 루트 노드일 경우
            *bst = GetRightSubTree(vNode);
        }

        free(vNode);
        return dNode;
        
    }
    


}

BTreeNode * BSTSearch(BTreeNode * bst, Data target) {

    BTreeNode * cNode = bst;
    Data cData;

    // 데이터가 일치하는 노드 탐색
    while (cNode != NULL) { 
        
        cData = BGetData(cNode);

        if (target == cData) {
            return cNode;
        } else if (target < cData) {
            cNode = GetLeftSubTree(cNode);
        } else {
            cNode = GetRightSubTree(cNode);
        }
    
    }
    
    return NULL;

}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt) {

    BTreeNode * dNode;

    if(bt != NULL) {
        dNode = bt->left;
        bt->left = NULL;
    }

    free(dNode);

}
BTreeNode * RemoveRightSubTree(BTreeNode * bt) {

    BTreeNode * dNode;

    if(bt != NULL) {
        dNode = bt->right;
        bt->right = NULL;
    }

    free(dNode);

}

BTreeNode * ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) {

    main->left = sub;

}

BTreeNode * ChangeRightSubTree(BTreeNode * main, BTreeNode * sub) {

    main->right = sub;

}
