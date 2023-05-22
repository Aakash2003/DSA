#include <bits/stdc++.h>
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

TreeNode *buildTree(vector<int> &postorder, map<int, int> &mp, int &index, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(postorder[index]);
    index--;

    if (inStart == inEnd)
        return root;

    int inIndex = mp[root->val];
    root->left = buildTree(postorder, mp, index, inStart, inIndex - 1);
    root->right = buildTree(postorder, mp, index, inIndex + 1, inEnd);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;
        
    int index = n - 1;
    return buildTree(postorder, mp, index, 0, n - 1);
}