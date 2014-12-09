/*
 * 将二叉搜索树转换成双向链表
 */
#include <iostream>
#include "MyBT.h"

using namespace std;

/* 将以root为根节点的二叉搜索树转换成双向链表。对BST，使用
 * 中序遍历可得到有序序列。
 * 利用类似中序遍历的过程进行转换。
 * p：指向双向链表的尾节点
 */
void ConvertNode(BTNode* root, BTNode** p)
{
    if(root == NULL)
        return;
    BTNode* pCurrent = root;
    //转换左子树
    if(pCurrent->pLeft != NULL)
        ConvertNode(pCurrent->pLeft, p);
    // 左子树转换好，链接链表尾节点和根节点
    pCurrent->pLeft = *p;
    if(*p != NULL)
        (*p)->pRight = pCurrent;
    // 连接后，根节点成为新的链表尾节点
    *p = pCurrent;
    //转换右子树
    if(pCurrent->pRight != NULL)
        ConvertNode(pCurrent->pRight, p);
}

BTNode* Convert(BTNode* root)
{
    BTNode *p = NULL;
    ConvertNode(root, &p);
    BTNode* pHead = p;
    while(pHead != NULL && pHead->pLeft != NULL)
        pHead = pHead->pLeft;
    return pHead;
}

void Test()
{
    BTNode* a0 = CreateBTNode(3);
    BTNode* a1 = CreateBTNode(1);
    BTNode* a2 = CreateBTNode(4);
    BTNode* a3 = CreateBTNode(0);
    BTNode* a4 = CreateBTNode(2);
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;
    a1->pRight = a4;
    cout << "给定的二叉搜索树为：" << endl;
    cout << "  3  " << endl;
    cout << " 1  4" << endl;
    cout << "0 2  " << endl;
    BTNode* p = Convert(a0);
    cout << "打印转换后的双向链表：" << endl;
    while(p != NULL)
    {
        cout << p->value << " ";
        p = p->pRight;
    }
    cout << endl;
}

int main()
{
    Test();
}
