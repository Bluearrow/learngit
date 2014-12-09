/* * Merge two sorted list, return the new head node.  * */ 
#include<iostream>
#include "ListHelper.h"

using namespace std;

ListNode* MergerList(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    ListNode* pNewHead = NULL;
    if(pHead1->value < pHead2->value)
    {
        pNewHead = pHead1;
        pNewHead->pNext = MergerList(pHead1->pNext, pHead2);
    }
    else
    {
        pNewHead = pHead2;
        pNewHead->pNext = MergerList(pHead1, pHead2->pNext);
    }
    
    return pNewHead;
}

int main()
{
    ListNode p11 = CreateNode(1);
    ListNode p12 = CreateNode(3);
    ConnectNode(&p11, &p12);
    ListNode p21 = CreateNode(2);
    ListNode p22 = CreateNode(4);
    ConnectNode(&p21, &p22);

    ListNode* pNewHead = MergerList(&p11, &p21);
    PrintList(pNewHead);

    return 0;
}
