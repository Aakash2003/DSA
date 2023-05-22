#include <bits/stdc++.h>
using namespace std;

int optimalSearch(vector<int> &keys, vector<int> &freq)
{
    int n = keys.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> prefix_sum(n);
    prefix_sum[0] = freq[0];

    for (int i = 1; i < n; i++)
        prefix_sum[i] += prefix_sum[i - 1] + freq[i];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (j == i)
                dp[i][j] = freq[i];
            else if (j == i + 1)
                dp[i][j] = min({freq[i] + 2 * freq[j], freq[j] + 2 * freq[i]});
            else
            {
                int mini = INT_MAX;
                int sum;

                if (i == 0)
                    sum = prefix_sum[j];
                else
                    sum = prefix_sum[j] - prefix_sum[i - 1];

                for (int k = i; k <= j; k++)
                {
                    int left = 0, right = 0;
                    if (k > i)
                        left = dp[i][k - 1];
                    if (k < j)
                        right = dp[k + 1][j];
                    mini = min(mini, left + right + sum);
                }

                dp[i][j] = mini;
            }
        }
    }

    return dp[0][n - 1];
}