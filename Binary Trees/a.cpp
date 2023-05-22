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

vector<string> split(string &s, char delimiter)
{
    vector<string> ans;
    stringstream ss(s);
    string output;

    while (getline(ss, output, delimiter))
        ans.push_back(output);

    return ans;
}

void serialize(TreeNode *node, string &s)
{
    if (node == NULL)
    {
        s.append("#,");
        return;
    }

    s.append(to_string(node->val) + ',');
    serialize(node->left, s);
    serialize(node->right, s);
}

TreeNode *deserialize(vector<string> arr, int index)
{
    int n = arr.size();
    if (index >= n || arr[index] == "#")
    {
        index++;
        return NULL;
    }

    TreeNode* node = new TreeNode(stoi(arr[index]));
    node->left = deserialize(arr,index+1);
    node->right = deserialize(arr,index+1);
    return node;
}

string serialize(TreeNode *root)
{
    string s = "";
    serialize(root, s);
    return s;
}

TreeNode *deserialize(string data)
{
    vector<string> arr = split(data, ',');
    int index = 0;
    return deserialize(arr,index);
}