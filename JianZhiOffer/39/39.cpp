/* 39.cpp
 * 求二叉树的深度
*/
#include <iostream>
#include "MyBT.h"

using namespace std;

// 寻找二叉树的深度，此思路可以扩展到任意树。
int FindBTDepth(BTNode* root)
{
    if(root == NULL)
        return 0;
    // 对左右孩子进行迭代
    l_Deepth = FindBTDepth(root->pLeft);
    r_Deepth = FindBTDepth(root->pRight);
    return 1 + (l_Deepth > r_Deepth ? l_Deepth:r_Deepth);
}

/* 判断一颗二叉树是否为平衡二叉树，用前面的找深度
 * 函数可以，但是时间复杂度高；利用后序遍历，依次
 * 求取每个节点的深度。
 * root ： 二叉树的根节点
 * depth ： 存放root的深度
 */
bool IsBTBalanced(BTNode* root, int* depth)
{
    if(root == NULL)
    {
        *depth = 0;
        return true;
    }
    int left, right;
    if(IsBTBalanced(root->pLeft,&left) 
            && IsBTBalanced(root->pRight,&right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *depth = 1 + (left>right?left:right);
            return true;
        }
    }
    return false;
}

bool IsBTBalanced(BTNode* root)
{
    int depth = 0;
    return IsBTBalanced(root, &depth);
}

/* 给定二叉树和一个节点，找出此节点的路径 */
void FindBTPath(BTNode* root, BTNode* pNode, vector<int> path)
{
    path.push_back(root->value);
    // path.push_back(root);
    if(root == pNode)
        return;
    if(root->pLeft != NULL)
        FindBTPath(root->pLeft, pNode, path);
    if(root->pRight != NULL)
        FindBTPath(root->pRight, pNode, path)

    path.pop_back();
}

void FindBTPath(BTNode* root, BTNode* pNode)
{
    if(root == NULL || pNode == NULL)
        return;
    vector<int> path;
    FindBTPath(root, pNode, path);
    vector<int>::iterator iter = path.begin();
    for(; iter != path.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

/* 给定一颗二叉树和两个节点，寻找它们的最低公共祖先。
 * 用两个vector将两个节点的路径保存先来，再寻找。
 */
BTNode* FindCommonParent(BTNode* root, BTNode* p1, BTNode* p2)
{
    if(root == NULL || p1 == NULL || p2 == NULL)
        return NULL;
    vector<BTNode*> path1;
    vector<BTNode*> path2;
    FindBTPath(root, p1, path1);
    FindBTPath(root, p2, path2);

    vector<BTNode*>::iterator iter_p1 = path1.begin();
    vector<BTNode*>::iterator iter_p2 = path2.begin();
    
    BTNode* result = NULL;
    while(iter_p1 != path1.end() && iter_p2 != path2.end())
    {
        if(*iter_p1 == *iter_p2)
            result = *iter_p1;
        iter_p1++;
        iter_p2++;
    }
    return result;
}
