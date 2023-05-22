#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(k + 1, vector<int>(n));

    for (int t = 1; t <= k; t++)
    {
        int maxi = INT_MIN;
        for (int d = 1; d < n; d++)
        {
            maxi = max(maxi, dp[t - 1][d - 1] - prices[d - 1]);
            dp[t][d] = max(dp[t][d - 1], maxi + prices[d]);
        }
    }

    return dp[k][n - 1];
}