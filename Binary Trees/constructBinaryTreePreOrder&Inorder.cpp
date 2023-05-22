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

TreeNode *buildTree(vector<int> &preorder, map<int, int> &mp, int &index, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index]);
    index++;

    if (inStart == inEnd)
        return root;

    int inIndex = mp[root->val];
    root->left = buildTree(preorder, mp, index, inStart, inIndex - 1);
    root->right = buildTree(preorder, mp, index, inIndex + 1, inEnd);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    int index = 0;
    return buildTree(preorder, mp, index, 0, n - 1);
}
