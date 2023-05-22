#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > 0)
        {
            int mini = INT_MAX;
            for (int j = 1; j <= nums[i] && i + j < n; j++)
            {
                if (dp[i + j] != INT_MAX)
                    mini = min(mini, dp[i + j]);
            }

            if (mini != INT_MAX)
                dp[i] = 1 + mini;
        }
    }

    return dp[0];
}