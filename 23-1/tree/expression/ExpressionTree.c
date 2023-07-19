#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <ctype.h>

#include "LStack.h"
#include "BinaryTree.h"


BTreeNode * MakeExpTree(char exp[]) {

    Stack stack;
    BTreeNode * node;

    int explen = strlen(exp);
    int i;

    StackInit(&stack);

    for (i = 0; i < explen; i++) {

        char tok = exp[i];

        if (isdigit(tok)) { // 피연사자 이면
            SPush(&stack, tok - '0');
        } else {

            MakeRightSubTree(node, SPop(&stack));
            MakeLeftSubTree(node, SPop(&stack));
            BSetData(node, tok);

        }

        SPush(&stack, node);
        
    }
    
    return SPop(&stack);

}


int EvaluateExpTree(BTreeNode * bt) {

    int op1, op2;

    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) {
        return BGetData(bt);
    }

    op1 = EvaluateExpTree(BGetData(GetLeftSubTree(bt)));
    op2 = EvaluateExpTree(BGetData(GetRightSubTree(bt)));

    switch (BGetData(bt)) {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    }

    return 0;

}

void ShowNodeData(int data) {

    if(0 <= data && data <= 9) {
        printf("%d ", data);
    } else {
        printf("%c ",data);
    }

}

void ShowPrefix(BTreeNode * bt) {

   PreorderTraverse(bt, ShowNodeData);

}

void ShowInfix(BTreeNode * bt) {
   
   InorderTraverse(bt, ShowNodeData);
    
}

void ShowPostfix(BTreeNode * bt) {

    PostorderTraverse(bt, ShowNodeData);

}