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

class BST
{
    TreeNode *root;

private:
    bool hasData(TreeNode *node, int data)
    {
        if (node == NULL)
            return false;

        if (node->val == data)
            return true;
        else if (node->val > data)
            return hasData(node->left, data);
        else
            hasData(node->right, data);
    }

    TreeNode *insert(TreeNode *node, int data)
    {
        if (node == NULL)
        {
            TreeNode *newNode = new TreeNode(data);
            return newNode;
        }

        if (node->val > data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    TreeNode *deleteData(TreeNode *node, int data)
    {
        if (node == NULL)
            return NULL;

        if (node->val > data)
        {
            node->left = deleteData(node->left, data);
            return node;
        }
        else if (node->val < data)
        {
            node->right = deleteData(node->right, data);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                TreeNode *right = node->right;
                node->right = NULL;
                delete node;
                return right;
            }
            else if (node->right == NULL)
            {
                TreeNode *left = node->left;
                node->left = NULL;
                delete node;
                return left;
            }
            else
            {
                TreeNode *mini = node->right;
                while (mini->left != NULL)
                    mini = mini->left;

                int min = mini->val;
                node->val = min;
                node->right = deleteData(node->right, min);
                return node;
            }
        }
    }

public:
    BST() { root = NULL; }
    ~BST() { delete root; }
    bool hasData(int data) { return hasData(root, data); }
    void insert(int data) { this->root = insert(root, data); }
    void deleteData(int data) { this->root = deleteData(root, data); }
};
