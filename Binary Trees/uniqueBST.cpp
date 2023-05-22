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

int numTrees(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int left = 0, right = i - 1;
        while (left <= i - 1)
        {
            dp[i] += dp[left] * dp[right];
            left++, right--;
        }
    }

    return dp[n];
}