#include <iostream>
#include "ListHelper.h"

using namespace std;

ListNode* RevsereList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    ListNode* pP = NULL;
    ListNode* pNewHead = NULL;

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

int main()
{
    ListNode p1 = CreateNode(1);
    ListNode p2 = CreateNode(2);
    ConnectNode(&p1, &p2);
    PrintList(&p1);
    ListNode* p = RevsereList(&p1);
    PrintList(p);
}
