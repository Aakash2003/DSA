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

int ans = 0;

pair<int, int> dfs(TreeNode *root)
{
    if (root == NULL)
        return {-1, -1};

    pair<int, int> left = dfs(root->left);
    pair<int, int> right = dfs(root->right);

    ans = max(ans, 1 + max(left.second, right.first));
    return {1 + left.second, 1 + right.first};
}

int longestZigZag(TreeNode *root)
{
    if (root == NULL)
        return 0;
        
    dfs(root);
    return ans;
}