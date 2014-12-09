#include <iostream>
#include "ListHelper.h"

using namespace std;

unsigned int GetListLength(ListNode* pHead)
{
    unsigned int length = 0;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        length++;
        pNode = pNode->pNext;
    }
    return length;
}

ListNode* FirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL || pHead2 == NULL)
        return NULL;
    unsigned int length1 = GetListLength(pHead1);
    unsigned int length2 = GetListLength(pHead2);
    int lengthDif = length1 - length2;
    ListNode* pFirst = pHead1;
    ListNode* pSecond = pHead2;
    if(lengthDif < 0)
    {
        lengthDif = length2 - length1;
        pFirst = pHead2;
        pSecond = pHead1;
    }

    for(int i=0; i < lengthDif; i++)
        pFirst = pFirst->pNext;

    while((pFirst != NULL) && (pFirst != pSecond))
    {
        pFirst = pFirst->pNext;
        pSecond = pSecond->pNext;
    }
    ListNode* pFirstCommonNode = pFirst;
    return pFirstCommonNode;
}

int main()
{
    ListNode* p1 = CreateNode(1);
    ListNode* p2 = CreateNode(2);
    ListNode* p3 = CreateNode(3);
    ListNode* p4 = CreateNode(4);
    ListNode* p5 = CreateNode(5);
    ConnectNode(p1,p2);
    ConnectNode(p2,p4);
    ConnectNode(p4,p5);
    ConnectNode(p3,p4);
    PrintList(p1);
    PrintList(p3);
    ListNode* p = FirstCommonNode(p1,p3);
    cout << p->value << endl;
}
