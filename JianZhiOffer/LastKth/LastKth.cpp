/*
 */
#include <iostream>
#include "ListHelper.h"

using namespace std;

// Output the last kth node of a lined list.
// Input:the pointer to the head node of the linked list and
// the k
// Output: pointer to the last kth node if successful, or
// the error information.
ListNode* LastKthNode(ListNode* pHead, unsigned int k)
{
    if(pHead == NULL || k == 0)
        return NULL;
    ListNode* p1 = pHead;
    for(int i=1; i < k; i++)
    {
        if(p1->pNext != NULL)
            p1 = p1->pNext;
        else
        {
            cout << "There is less k nodes in the list." << endl;
            return NULL;
        }
    }
    ListNode* p2 = pHead;
    while(p1->pNext != NULL)
    {
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    return p2;
}

// Test: input is NULL
void Test1()
{
    ListNode p1 = CreateNode(1);
    ListNode p2 = CreateNode(2);
    ListNode p3 = CreateNode(3);
    ListNode p4 = CreateNode(4);
    ListNode p5 = CreateNode(5);
    ConnectNode(&p1,&p2);
    ConnectNode(&p2,&p3);
    ConnectNode(&p3,&p4);
    ConnectNode(&p4,&p5);
    PrintList(&p1);
    ListNode* p = LastKthNode(&p5, 1);
    cout << p->value << endl;
}

int main()
{
    Test1();
}
