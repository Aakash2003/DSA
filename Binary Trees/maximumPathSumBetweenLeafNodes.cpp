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

int dfs(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return -1;
    else if (root->left == NULL && root->right == NULL)
        return root->val;

    int left = dfs(root->left, maxi);
    int right = dfs(root->right, maxi);

    if (root->left != NULL && root->right != NULL)
        maxi = max(maxi, left + root->val + right);
    else if (root->left == NULL)
        return right + root->val;
    else
        return left + root->val;
}

int maxPathSum(TreeNode *root)
{
    int maxi = -1;
    dfs(root, maxi);
    return maxi;
}