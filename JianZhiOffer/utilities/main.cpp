#include <iostream>
#include "ListHelper.h"

using namespace std;

int main()
{
    ListNode* p1 = CreateNode(1);
    ListNode* p2 = CreateNode(2);
    ListNode* p3 = CreateNode(3);
    ConnectNode(p1,p2);
    ConnectNode(p2,p3);
    PrintList(p1);
    PrintListReversed(p1);
    DeleteNode(&p1, p2);
    PrintList(p1);
    DestroyList(p1);
    return 0;
}
