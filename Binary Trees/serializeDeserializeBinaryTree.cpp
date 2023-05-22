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

string serialize(TreeNode *root)
{
    string s = "";
    if (root == NULL)
        return s;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == NULL)
            s.append("#,");
        else
            s.append(to_string(node->val) + ',');

        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }

    return s;
}

TreeNode *deserialize(string data)
{
    int n = data.length();
    if (n == 0)
        return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');

        if (str == "#")
            node->left = NULL;
        else
        {
            TreeNode *left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }

        getline(s, str, ',');

        if (str == "#")
            node->right = NULL;
        else
        {
            TreeNode *right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
    }

    return root;
}