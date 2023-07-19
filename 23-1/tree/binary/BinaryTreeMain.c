#include <stdio.h>
#include "BinaryTree.h"


int main() {


    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    BTreeNode * bt5 = MakeBTreeNode();
    BTreeNode * bt6 = MakeBTreeNode();

    BSetData(bt1, 1);
    BSetData(bt2, 2);
    BSetData(bt3, 3);
    BSetData(bt4, 4);
    BSetData(bt5, 5);
    BSetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);

    PreorderTraverse(bt1, ShowIntData);
    printf("\n");

    InorderTraverse(bt1, ShowIntData);
    printf("\n");

    PostorderTraverse(bt1, ShowIntData);
    printf("\n");

    return 0;

}

void ShowIntData(int data) {
    printf("%d \n", data);
}
