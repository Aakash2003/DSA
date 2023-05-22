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

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
        
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        TreeNode *node = itr.first;
        int line = itr.second;
        if (mp.count(line) == 0)
            mp[line] = node->val;

        if (node->left != NULL)
            q.push({node->left, line - 1});
        if (node->right != NULL)
            q.push({node->right, line + 1});
    }

    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}