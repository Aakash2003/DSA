#include <bits/stdc++.h>
using namespace std;

int LCSof3(string s1, string s2, string s3)
{
    int n = s1.length(), m = s2.length(), l = s3.length();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (int k = l - 1; k >= 0; k--)
            {
                char c1 = s1[i], c2 = s2[j], c3 = s3[k];
                if (c1 == c2 && c2 == c3)
                    dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
                else
                    dp[i][j][k] = max({dp[i + 1][j][k], dp[i][j + 1][k], dp[i][j][k + 1]});
            }
        }
    }

    return dp[0][0][0];
}