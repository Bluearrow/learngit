#include <iostream>
#include "ListHelper.h"

using namespace std;

// Split a list from its middle node.
ListNode* SplitList(ListNode* pHead)
{
    if(pHead == NULL || pHead->pNext == NULL ||
            pHead->pNext->pNext == NULL)
        return pHead;
    ListNode* p1 = pHead;
    ListNode* p2 = pHead;
    // Find the middle node.
    while(p1->pNext->pNext != NULL)
    {
        p1 = p1->pNext->pNext;
        p2 = p2->pNext;
        if(p1->pNext == NULL)
            break;
    }
    ListNode* pHead1 = p2->pNext;
    p2->pNext = NULL;
    return pHead1;
}

// Reverse a list.
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    ListNode* pNewHead = NULL;
    ListNode* pP = NULL;
    while(pNode != NULL)
    {
        ListNode* pN = pNode->pNext;
        if(pN == NULL)
            pNewHead = pNode;
        pNode->pNext = pP;
        pP = pNode;
        pNode = pN;
    }
    return pNewHead;
}

// Merge two list: m0,m1,... and n0,n1,.. into m0,n0,m1,n2,...
void MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL || pHead2 == NULL)
        return;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while(p2 != NULL)
    {
        ListNode* p1N = p1->pNext;
        ListNode* p2N = p2->pNext;
        // Insert p2 between p1 and p1N.
        p1->pNext = p2;
        p2->pNext = p1N;
        if(p2N == NULL)
            break;
        p1 = p1N;
        p2 = p2N;
    }
}

void RearrangeList(ListNode* pHead)
{
    ListNode* pHead1 = SplitList(pHead);
    ListNode* pHead2 = ReverseList(pHead1);
    MergeList(pHead, pHead2);
}

int main()
{
    ListNode* p1 = CreateNode(1);
    ListNode* p2 = CreateNode(2);
    ListNode* p3 = CreateNode(3);
    ListNode* p4 = CreateNode(4);
    ListNode* p5 = CreateNode(5);
    ConnectNode(p1,p2);
    ConnectNode(p2,p3);
    ConnectNode(p3,p4);
    ConnectNode(p4,p5);
    PrintList(p1);
    RearrangeList(p1);
    DestroyList(p1);
    return 0;
}
