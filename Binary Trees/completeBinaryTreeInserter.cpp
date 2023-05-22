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

class CBTInserter
{
private:
    TreeNode *node = NULL;
    TreeNode *next = NULL;
    queue<TreeNode *> q;

public:
    CBTInserter(TreeNode *root)
    {
        node = root;
        q.push(node);

        while (true)
        {
            TreeNode *front = q.front();
            q.pop();

            if (front->left != NULL)
                q.push(front->left);
            else
            {
                next = front;
                break;
            }

            if (front->right != NULL)
                q.push(front->right);
            else
            {
                next = front;
                break;
            }
        }
    }

    int insert(int val)
    {
        if (next->left == NULL)
        {
            TreeNode *newNode = new TreeNode(val);
            next->left = newNode;
            q.push(newNode);
        }
        else
        {
            TreeNode *newNode = new TreeNode(val);
            next->right = newNode;
            q.push(newNode);
            q.pop();
            next = q.front();
        }

        return next->val;
    }

    TreeNode *get_root()
    {
        return node;
    }
};