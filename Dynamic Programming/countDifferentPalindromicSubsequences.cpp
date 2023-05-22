#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9 + 7);

int countPalindromicSubsequences(string s)
{
    int n = s.length();
    int mod = (int)(1e9 + 7);
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> prev(n), next(n);
    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (mp.count(ch) == 0)
            prev[i] = -1;
        else
            prev[i] = mp[ch];

        mp[ch] = i;
    }

    mp.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (mp.count(ch) == 0)
            next[i] = n;
        else
            next[i] = mp[ch];

        mp[ch] = i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (j == i)
                dp[i][j] = 1;
            else if (j == i + 1)
                dp[i][j] = 2;
            else
            {
                char c1 = s[i], c2 = s[j];
                if (c1 != c2)
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1]) % mod;
                else
                {
                    int nextIndex = next[i];
                    int prevIndex = prev[j];

                    if (prevIndex < nextIndex)
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod + 2) % mod;
                    else if (prevIndex == nextIndex)
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod + 1) % mod;
                    else
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod - dp[nextIndex + 1][prevIndex - 1]) % mod;
                }
            }
        }
    }

    if (dp[0][n - 1] < 0)
        dp[0][n - 1] += mod;

    return dp[0][n - 1];
}