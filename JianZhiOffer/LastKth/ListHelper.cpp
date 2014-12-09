#include <iostream>
#include "ListHelper.h"

using namespace std;

ListNode CreateNode(int value)
{
    ListNode aNode;
    aNode.value = value;
    aNode.pNext = NULL;
    
    return aNode;
}

void ConnectNode(ListNode* p1, ListNode* p2)
{
    if((p1 != NULL) && (p2 != NULL))
        p1->pNext = p2;
    else
        cout << "Iput two NULL ListNode." << endl;
}

void PrintList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        cout << pNode->value << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}
