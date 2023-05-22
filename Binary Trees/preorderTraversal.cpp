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

TreeNode *rightMostNode(TreeNode *left_node, TreeNode *curr)
{
    while (left_node->right != NULL && left_node->right != curr)
        left_node = left_node->right;

    return left_node;
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        TreeNode *left_node = curr->left;
        if (left_node == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *right_most = rightMostNode(left_node, curr);

            if (right_most->right == NULL)
            {
                ans.push_back(curr->val);
                right_most->right = curr;
                curr = curr->left;
            }
            else
            {
                right_most->right = NULL;
                curr = curr->right;
            }
        }
    }

    return ans;
}