#include <iostream>
#include "ListHelper.h"

using namespace std;

ListNode* CreateNode(int value)
{
    ListNode* aNode = new ListNode();
    aNode->value = value;
    aNode->pNext = NULL;
    
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

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->pNext;
        delete pHead;
        pNode = pHead;
    }
}

void PrintListReversed(ListNode* pHead)
{
    if(pHead == NULL)
        return;
    else
    {
        PrintListReversed(pHead->pNext);
        cout << pHead->value << " ";
    }
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
    if(pHead == NULL || pToBeDeleted == NULL)
   {
       cout<< "Input is not proper." << endl;
       return;
   }
    if(pToBeDeleted->pNext != NULL)
    {
        ListNode* pN = pToBeDeleted->pNext;
        pToBeDeleted->value = pN->value;
        pToBeDeleted->pNext = pN->pNext;

        delete pN;
        pN = NULL;
    }
    else if(pToBeDeleted == *pHead)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pHead = NULL;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->pNext != pToBeDeleted)
        {
            pNode = pNode->pNext;
        }
        pNode->pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
