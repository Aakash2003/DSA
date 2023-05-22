#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.length(), m = s2.length();
    if (s3.length() != n + m)
        return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
            {
                if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
            else if (j == 0)
            {
                if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}