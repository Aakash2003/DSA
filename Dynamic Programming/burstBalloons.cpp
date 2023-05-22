#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = 0, right = 0;
                if (k > i)
                    left = dp[i][k - 1];
                if (k < j)
                    right = dp[k + 1][j];

                int val = nums[k];
                if (i > 0)
                    val *= nums[i - 1];
                if (j < n - 1)
                    val *= nums[j + 1];

                int total = left + right + val;
                maxi = max(maxi, total);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[0][n - 1];
}