#include <iostream>
#include "ListHelper.h"
using namespace std;

int main()
{
    ListNode p1 = CreateNode(1);
    ListNode p2 = CreateNode(2);
    ConnectNode(&p1, &p2);
    PrintList(&p1);

    return 0;
}
