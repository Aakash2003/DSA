#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    int n = p.length(), m = s.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n && j == m)
                dp[i][j] = true;
            else if (i == n)
                dp[i][j] = false;
            else if (j == m)
            {
                if (p[i] == '*')
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                if (p[i] == s[j] || p[i] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (p[i] == '*')
                    dp[i][j] = dp[i + 1][j] | dp[i][j + 1];
                else
                    dp[i][j] = false;
            }
        }
    }

    return dp[0][0];
}