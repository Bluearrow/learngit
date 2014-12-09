/* 24.cpp
 * 判断给定数组是否为二叉搜索树的后序遍历序列。
 * */
# include <iostream>
# include "MyBT.h"

using namespace std;

bool Hi(int* A, int length)
{
    if(A==NULL || length < 0)
        return false;
    int root_value = A[length-1];
    int i = 0;
    // 寻找左子树和右子树的分界点
    for(; i < length - 1; i++)
    {
        if(A[i] > root_value)
            break;
    }
    // 检查右子树是否有小于根节点的元素，若有，则不是BST。
    for(int j = i; j < length - 1; j++)
    {
        if(A[j] < root_value)
            return false;
    }
    // 递归判断两个序列是否为BST的后序遍历序列。
    if(i > 0)
        bool left = Hi(A, i);
    if(i < length - 1)
        bool right = Hi(A+i, length-i-1);
    return left && right;
}

void Test()
{
    int a[] = {0, 2,1,5,4,3};
    if(Hi(a,6) == true)
        cout << "Test passed." << endl;
    else
        cout << "Test failed." << endl;
}

int main()
{
    Test();
}
