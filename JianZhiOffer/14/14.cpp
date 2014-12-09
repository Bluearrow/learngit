/* 14.cpp
 * Reorder an integer array so that all of its odd elements are 
 * in front of even elements.
 * */

#include <iostream>
using namespace std;

void ReorderArray(int *start, int *end)
{
    if(start == NULL || end == NULL || start >= end)
        return;
    while(start < end)
    {
        //while(*start % 2 == 1)
        while(start < end && (*start & 0x1) != 0)
            start++;
        //while(*end % 2 == 0)
        while(start < end && (*end & 0x1) == 0)
            end--;
        if(start < end)
        {
            int tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
}

bool IsOdd(int n)
{
    return (n & 0x1 == 1) ? true : false;
}

bool IsNegtive(int n)
{
    return n > 0 ? false : true;
}

void ReorderArray(int *start, int *end, bool (*func)(int))
{
    while(start < end)
    {
        while(start < end && func(*start))
            start++;
        while(start < end && !func(*end))
            end--;
        if(start < end)
        {
            int tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
}
void Test()
{
    int a[] = {1, -2, 3, -1, 5};
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    ReorderArray(a, a+4, IsNegtive);
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    Test();
}
