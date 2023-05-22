#include <bits/stdc++.h>
using namespace std;

int knapsack(int w, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= wt[i - 1])
            {
                int rest = j - wt[i - 1];
                if (dp[i - 1][rest] + val[i - 1] > dp[i - 1][j])
                    dp[i][j] = dp[i - 1][rest] + val[i - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}