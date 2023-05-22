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

pair<int, int> heightDiameter(TreeNode *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> left = heightDiameter(root->left);
    pair<int, int> right = heightDiameter(root->right);

    int height = 1 + max(left.first, right.first);
    int diameter = max(left.first + right.first, max(left.second, right.second));
    return {height, diameter};
}

int diameterOfBinaryTree(TreeNode *root)
{
    if(root==NULL) return 0;
    return heightDiameter(root).second;
}