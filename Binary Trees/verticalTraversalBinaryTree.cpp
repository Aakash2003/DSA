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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        TreeNode *node = front.first;
        int x = front.second.first, y = front.second.second;
        mp[x][y].insert(node->val);

        if (node->left != NULL)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right != NULL)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (auto i : mp)
    {
        vector<int> output;
        for (auto j : i.second)
            output.insert(output.end(), j.second.begin(), j.second.end());
        ans.push_back(output);
    }

    return ans;
}