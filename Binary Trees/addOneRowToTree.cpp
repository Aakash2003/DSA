#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    if(depth==1)
    {
        TreeNode* ans = new TreeNode(val);
        ans->left = root;
        return ans;
    }

    
}