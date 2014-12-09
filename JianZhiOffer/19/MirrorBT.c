/* Mirrow.c
 * 给定一个二叉树，输出次树的镜像。
 */
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

//
void MirrorBT(BTNode* root)
{
    if(root == NULL)
        return;
    if(root->pLeft == NULL && root->pRight == NULL)
        return;

    BTNode* tmp = root->pLeft;
    root->pLeft = root->pRight;
    root->pRight = tmp;

    if(root->pLeft)
        MirrorBT(root->pLeft);
    if(root->pRight)
        MirrorBT(root->pRight);
}
/* a0  1
 *    2 3
 *   4   5
 */
void Test()
{
    BTNode* a0 = CreateBTNode(1);
    BTNode* a1 = CreateBTNode(2);
    BTNode* a2 = CreateBTNode(3);
    BTNode* a3 = CreateBTNode(4);
    BTNode* a4 = CreateBTNode(5);
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;
    a2->pRight = a4;
    PrintBT(a0);
    printf("\n");
    MirrorBT(a0);
    PrintBT(a0);
    printf("\n");
}

int main()
{
    Test();
    return 0;
}
