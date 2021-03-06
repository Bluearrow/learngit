/* MyBT.h
 * 自定义的二叉树的数据结构
 */

#ifndef MYBT_H
#define MYBT_H

#include <stdio.h>
#include <stdlib.h>

// Defintion of binary tree node.
struct BTNode
{
    int value;
    BTNode* pLeft;
    BTNode* pRight;
};

BTNode* CreateBTNode(int a_value)
{
    BTNode* p = (BTNode*)malloc(sizeof(struct BTNode));
    p->value = a_value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
// Pre-order reverse.
void PrintBT(BTNode* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->value);
    PrintBT(root->pLeft);
    PrintBT(root->pRight);
}

#endif
