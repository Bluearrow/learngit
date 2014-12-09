/* 23.cpp
 * 按深度打印树，借用C++标准队列模板。
 */

#include <iostream>
#include "MyBT.h"
//#include "MyQueue.h"
#include <queue>

using namespace std;

/*
void PrintBTFTTD(BTNode* root)
{
    if(root == NULL)
        return;
    MyQueue<BTNode*> q1;
    q1.EnQueue(root);
    while(q1.len())
    {
        BTNode* a = q1.DeQueue();
        cout << a->value << " ";

        if(a->pLeft)
            q1.EnQueue(a->pLeft);
        if(a->pRight)
            q1.EnQueue(a->pRight);
    }
    cout << endl;
}
*/
void PrintBTFTTD(BTNode* root)
{
    if(root == NULL)
        return;
    deque<BTNode*> q;
    q.push_back(root);
    while(q.size())
    {
        BTNode* n = q.front();
        q.pop_front();
        printf("%d ", n->value);
        if(n->pLeft)
            q.push_back(n->pLeft);
        if(n->pRight)
            q.push_back(n->pRight);
    }
}

void Test()
{
    BTNode* a0 = CreateBTNode(0);
    BTNode* a1 = CreateBTNode(1);
    BTNode* a2 = CreateBTNode(2);
    BTNode* a3 = CreateBTNode(3);
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;

    printf("The tree is:\n");
    printf("  0  \n");
    printf(" 1 2\n");
    printf("3\n");
    printf("按深度遍历的结果：\n");
    PrintBTFTTD(a0);
    printf("\n");
}

int main()
{
    Test();
}
