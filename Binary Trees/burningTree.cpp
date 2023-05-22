#include<bits/stdc++.h>
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

TreeNode* bfs(TreeNode* root,int target,map<TreeNode*,TreeNode*> &mp)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* ans;

    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if(node->val==target) ans = node;

        if(node->left!=NULL)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }

    return ans;
}

int solve(map<TreeNode*,TreeNode*> &mp,TreeNode* node)
{
    queue<TreeNode*> q;
    q.push(node);
    map<TreeNode*,bool> visited;
    visited[node] = true;
    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        int flag = 0;

        for(int i=0;i<size;i++)
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->left!=NULL && !visited[front->left])
            {
                flag = 1;
                visited[front->left] = true;
                q.push(front->left);
            }
            if(front->right!=NULL && !visited[front->right])
            {
                flag = 1;
                visited[front->right] = true;
                q.push(front->right);
            }
            if(mp[front]!=NULL && !visited[mp[front]])
            {
                flag = 1;
                visited[mp[front]] = true;
                q.push(mp[front]);
            }
        }

        if(flag==1) time++;
    }

    return time;
}

int minTime(TreeNode* root,int target)
{
    map<TreeNode*,TreeNode*> mp;
    TreeNode* node = bfs(root,target,mp);
    int time = solve(mp,node);
    return time;
}