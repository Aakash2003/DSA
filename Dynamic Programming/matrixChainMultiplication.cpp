#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (j == i)
                dp[i][j] = 0;
            else if (j == i + 1)
                dp[i][j] = arr[i - 1] * arr[i] * arr[j];
            else
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                    mini = min(mini, dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                dp[i][j] = mini;
            }
        }
    }

    return dp[1][n - 1];
}