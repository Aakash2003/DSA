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

int left_cnt = 0, right_cnt = 0;

int cnt(TreeNode *root, int n, int x)
{
    if (root == NULL)
        return 0;

    int left = cnt(root->left, n, x);
    int right = cnt(root->right, n, x);

    if (root->val == x)
        left_cnt = left, right_cnt = right;

    return left + right + 1;
}

bool btreeGameWinningMove(TreeNode *root, int n, int x)
{
    left_cnt = 0,right_cnt = 0;
    cnt(root,n,x);
    int top_cnt = n-(left_cnt+right_cnt+1);
    int maxi = max({left_cnt,right_cnt,top_cnt});
    return maxi>n/2;
}