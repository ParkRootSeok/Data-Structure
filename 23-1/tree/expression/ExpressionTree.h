#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"


BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefix(BTreeNode * bt);
void ShowInfix(BTreeNode * bt);
void ShowPostfix(BTreeNode * bt);

#endif