#include <bits/stdc++.h>
using namespace std;

int LEVEL = 16;

long long powerOfTwo(int x)
{
    return (1 << x);
}

typedef struct Node
{
    Node *left;
    Node *right;
    int cnt;

    Node()
    {
        left = NULL;
        right = NULL;
        cnt = 0;
    }
} Node;

int getCnt(Node *node)
{
    if (node == NULL)
        return 0;
    return node->cnt;
}

void insert(Node *node, int val)
{
    for (int i = LEVEL; i >= 0; i--)
    {
        int mask = (int)powerOfTwo(i);
        int bit = 0;
        if (val & mask)
            bit = 1;

        if (bit == 0)
        {
            if (node->left == NULL)
                node->left = new Node();
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
                node->right = new Node();
            node = node->right;
        }

        node->cnt += 1;
    }
}

int query(Node *node, int high, int val, int index)
{
    if (index < 0)
        return getCnt(node);
    if (node == NULL)
        return 0;

    int bit_val = 0, bit_high = 0;
    if (val & powerOfTwo(index))
        bit_val = 1;
    if (high & powerOfTwo(index))
        bit_high = 1;

    if (bit_val == 0)
    {
        if (bit_high == 0)
            return query(node->left, high, val, index - 1);
        else
            return getCnt(node->left) + query(node->right, high, val, index - 1);
    }
    else
    {
        if (bit_high == 0)
            return query(node->right, high, val, index - 1);
        else
            return query(node->left, high, val, index - 1) + getCnt(node->right);
    }
}

int countPairs(vector<int> &nums, int low, int high)
{
    int n = nums.size();
    Node *root = new Node();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += query(root, high, nums[i], LEVEL);
        cnt -= query(root, low - 1, nums[i], LEVEL);
        insert(root, nums[i]);
    }

    return cnt;
}