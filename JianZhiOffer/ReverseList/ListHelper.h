#include<iostream>
using namespace std;

// Definition of Listnode.
struct ListNode
{
    int value;
    ListNode* pNext;
};

// Create a new node.
ListNode CreateNode(int value);
// Conncet two node.
void ConnectNode(ListNode* p1, ListNode* p2);

// Print the value of very node.
void PrintList(ListNode* pHead);
