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

int num_cameras = 0;

int dfs(TreeNode *root)
{
    if (root == NULL)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == -1 || right == -1)
    {
        num_cameras++;
        return 0;
    }

    if (left == 0 || right == 0)
        return 1;

    return -1;
}

int minCameraCover(TreeNode *root)
{
    if (dfs(root) == -1)
        num_cameras++;
        
    return num_cameras;
}