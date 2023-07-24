#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"


void BSTreeInit(BTreeNode ** bst);

Data BSTGetData(BTreeNode * bst);

void BSTInsert(BTreeNode ** bst, Data data);
BTreeNode * BSTDelete(BTreeNode ** bst, Data target);

BTreeNode * BSTSearch(BTreeNode * bst, Data data);

BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
BTreeNode * ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
BTreeNode * ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif