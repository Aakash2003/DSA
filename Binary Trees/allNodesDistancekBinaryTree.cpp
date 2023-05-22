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

void markParents(TreeNode *root, TreeNode *target, map<TreeNode *, TreeNode *> &mp)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != NULL)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    map<TreeNode *, TreeNode *> mp;
    markParents(root, target, mp);
    map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (curr_level == k)
            break;
        curr_level++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right != NULL && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (mp[node] != NULL && !visited[mp[node]])
            {
                q.push(mp[node]);
                visited[mp[node]] = true;
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        ans.push_back(node->val);
    }

    return ans;
}