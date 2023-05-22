#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    if (n != m)
        return false;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1)));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            for (int j = 0; j <= n - len; j++)
            {
                if (len == 1)
                {
                    if (s1[i] == s2[j])
                        dp[i][j][len] = true;
                    else
                        dp[i][j][len] = false;
                }
                else
                {
                    for (int k = 1; k < len; k++)
                    {
                        dp[i][j][len] = (dp[i][j][k] && dp[i + k][j + k][len - k]) | (dp[i][j + len - k][k] && dp[i + k][j][len - k]);
                        if (dp[i][j][len] == true)
                            break;
                    }
                }
            }
        }
    }

    return dp[0][0][n];
}