#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    int n = p.length(), m = s.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
            {
                char ch = p[i - 1];
                if (ch == '*')
                    dp[i][j] = dp[i - 2][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                char c1 = p[i - 1], c2 = s[j - 1];

                if (c1 == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    char c3 = p[i - 2];
                    if (c3 == '.' || c3 == c2)
                        dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
                else if (c1 == c2 || c1 == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}