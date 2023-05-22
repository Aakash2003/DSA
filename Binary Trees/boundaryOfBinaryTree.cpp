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

void leftBoundary(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    ans.push_back(node->val);

    if (node->left != NULL)
        leftBoundary(node->left, ans);
    else
        leftBoundary(node->right, ans);
}

void leafNodes(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    if (node->left == NULL && node->right == NULL)
    {
        ans.push_back(node->val);
        return;
    }

    leafNodes(node->left, ans);
    leafNodes(node->right, ans);
}

void rightBoundary(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    if (node->right != NULL)
        rightBoundary(node->right, ans);
    else
        rightBoundary(node->left, ans);

    ans.push_back(node->val);
}

vector<int> boundary(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->val);
    leftBoundary(root->left, ans);
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
    rightBoundary(root->right, ans);
    return ans;
}