/* 18.c
 * 给定两颗二叉树A和B，判断B是否为A的子树。
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

/* 判断root2是否从root1的根节点开始就是它的一部分
 */
bool Hello(BTNode* root1, BTNode* root2)
{
    bool result = true;
    if(root1 != NULL && root2 != NULL)
    {
        if(root1->value == root2->value)
            return Hello(root1->pLeft, root2->pLeft) &&
                Hello(root1->pRight, root2->pRight);
        else
            result = false;
    }
    else if(root1 == NULL && root2 != NULL)
        result = false;
    return result;
}
/* a0 2
 *   4 5
 *  6
 * b0 2
 *   4 5
 */
void TestHello()
{
    BTNode* a0 = CreateBTNode(2);
    BTNode* a1 = CreateBTNode(4);
    BTNode* a2 = CreateBTNode(5);
    BTNode* a3 = CreateBTNode(6);
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;
    PrintBT(a0);
    printf("\n");
    BTNode* b0 = CreateBTNode(2);
    BTNode* b1 = CreateBTNode(4);
    BTNode* b2 = CreateBTNode(6);
    b0->pLeft = b1;
    b0->pRight = b2;
    PrintBT(b0);
    printf("\n");
    if(Hello(a0,b0) == true)
        printf("TestHello passes!\n");
    else
        printf("Testhello failed.\n");
}

/* 判断root2是否是root1的子树。如果root2从root1的
 * 根节点开始就是root1的一部分，返回真；否则递归判断
 * root2是否从根节点开始就为root1的左右子树的一部分。*/
bool IsSubtree(BTNode* root1, BTNode* root2)
{
    bool result = false;
    if(Hello(root1, root2))
        result = true;
    else
        result = Hello(root1->pLeft, root2) ||
            Hello(root1->pRight, root2);
    return result;
}
/*   a4 1
 *     2 3
 *    4 5
 *   6
 * b0 2
 *   4 5
 */
void Test()
{
    BTNode* a0 = CreateBTNode(2);
    BTNode* a1 = CreateBTNode(4);
    BTNode* a2 = CreateBTNode(5);
    BTNode* a3 = CreateBTNode(6);
    BTNode* a4 = CreateBTNode(1);
    BTNode* a5 = CreateBTNode(3);
    a4->pLeft = a0;
    a4->pRight = a5;
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;
    PrintBT(a4);
    printf("\n");
    BTNode* b0 = CreateBTNode(2);
    BTNode* b1 = CreateBTNode(4);
    BTNode* b2 = CreateBTNode(5);
    b0->pLeft = b1;
    b0->pRight = b2;
    PrintBT(b0);
    printf("\n");
    if(IsSubtree(a4, b0) == true)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
 
}
int main()
{
    //TestHello();
    Test();
}
