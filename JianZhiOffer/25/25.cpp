/* 25.cpp
 * 打印二叉树中和为某一值的所有路径。
 */

#include <iostream>
#include <vector>
#include "MyBT.h"
using namespace std;

// 基于栈的二叉树的先序遍历序列
void PrintBTI(BTNode* root)
{
    vector<BTNode*> path;
    while(root != NULL || !path.empty())
    {
        if(root != NULL)
        {
            cout << root->value << " ";
            path.push_back(root);
            root = root->pLeft;
        }
        else
        {
            root = path.back();
            path.pop_back();
            root = root->pRight;
        }
    }
}

/* 寻找以root为根节点的二叉树中符合条件的路径
 * root： 某颗二叉树的根节点
 * expected_sum： 给定路径之和
 * path： 存储候选路径的节点
 * current_sum : 已被存储的路径节点的值之和
 */
void FindPath(BTNode* root, int expected_sum, 
        vector<int> path, int current_sum)
{
    current_sum += root->value;
    path.push_back(root->value);
    // 如果root是叶节点并且路径和为给定值，则找到一条路径。
    if(root->pLeft == NULL && root->pRight == NULL
            && current_sum == expected_sum)
    {
        cout << "Find a path: ";
        vector<int>::const_iterator iter = path.begin();
        for(;iter != path.end(); ++iter)
            cout << *iter << " ";
        cout << endl;
    }
    // 如果不是叶节点，对其孩子节点递归调用此过程。
    if(root->pLeft != NULL)
        FindPath(root->pLeft, expected_sum, path, current_sum);
    if(root->pRight != NULL)
        FindPath(root->pRight, expected_sum, path, current_sum);
    // 如果是叶节点，但路径和不等于给定值，则弹出此节点。
    path.pop_back();
}


void FindPath1(BTNode* root, int expected_sum)
{
    if(root == NULL)
        return;
    int current_sum = 0;
    vector<int> path;
    FindPath(root,expected_sum,path,current_sum);
}

// 测试基于栈的先序遍历。
void Test1()
{
    BTNode* a0 = CreateBTNode(1);
    BTNode* a1 = CreateBTNode(2);
    BTNode* a2 = CreateBTNode(3);
    BTNode* a3 = CreateBTNode(4);
    BTNode* a4 = CreateBTNode(6);
    BTNode* a5 = CreateBTNode(5);
    a0->pLeft = a1;
    a0->pRight = a2;
    a1->pLeft = a3;
    a1->pRight = a4;
    a2->pRight = a5;
    cout << "The tree is:" << endl;
    cout << "    1      " <<endl;
    cout << "  2    3    " <<endl;
    cout << " 4  6    5" <<endl;
   // PrintBT(a0);
   // cout << endl;
    FindPath1(a0,9);
}

int main()
{
    Test1();
}
