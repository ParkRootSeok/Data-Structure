#include <stdio.h>
#include "ExpressionTree.h"

int main() {

    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("Preorder : ");
    ShowPrefix(eTree);
    printf("\n");

    printf("Inorder : ");
    ShowInfix(eTree);
    printf("\n");

    printf("Postorder : ");
    ShowPostfix(eTree);
    printf("\n");
    

    printf("result : %d", EvaluateExpTree(eTree));

    return 0;

}