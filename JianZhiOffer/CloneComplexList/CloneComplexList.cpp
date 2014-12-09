/* CloneComplexList.cpp
 *
 * */

#include <iostream>
using namespace std;

struct ComplexListNode
{
    int value;
    ComplexListNode* pNext;
    ComplexListNode* pSibling;
};

void CloneAllNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        // Clone pNode.
        ComplexListNode* pNodeNew = new ComplexListNode();
        pNodeNew->value = pNode->value;
        pNodeNew->pNext = pNode->pNext;
        pNodeNew->pSibling = NULL;
        // Insert it.
        pNode->pNext = pNodeNew;
        // Move to next node.
        pNode = pNodeNew->pNext;
    }
}

void ConnectSiblings(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        if(pNode->pSibling != NULL)
            // Connect sibling of the cloned node
            pNode->pNext->pSibling = pNode->pSibling->pNext;
        // Move to next node
        pNode = pNode->pNext->pNext;
    }
}

ComplexListNode* SplitList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    // The head of the cloned list.
    ComplexListNode* pCloneHead = NULL;
    if(pNode != NULL)
        pCloneHead = pHead->pNext;
    // Split the list.
    while(pNode != NULL)
    {
        ComplexListNode* pCloneNode = pNode->pNext;
        // Connect the original nodes.
        pNode->pNext = pCloneNode->pNext;
        // Move to next node.
        pNode = pNode->pNext;
        // Connect cloned nodes. 
        pCloneNode->pNext = pNode->pNext;
    }
    return pCloneHead;
}
