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

TreeNode* solve(TreeNode* root,TreeNode* &prev)
{
    if(root==NULL) return NULL;
    TreeNode* left = solve(root->left,prev);

    if(prev==NULL) left=root;
    else
    {
        prev->right = root;
        root->left = prev;
    }

    prev = root;
    solve(root->right,prev);
    return left;
}

TreeNode* bstToSortedDLL(TreeNode* root)
{
    if(root==NULL) return NULL;
    TreeNode* prev = NULL;
    return solve(root,prev);
}