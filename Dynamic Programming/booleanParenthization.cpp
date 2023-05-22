#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mod = (int)1003;

int countWays(string s)
{
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            for (int flag = 0; flag < 2; flag++)
            {
                if (j == i)
                {
                    if (flag == 0 && s[i] == 'F')
                        dp[i][j][flag] = 1;
                    if (flag == 1 && s[i] == 'T')
                        dp[i][j][flag] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int k = i + 1; k < j; k += 2)
                    {
                        int lf = dp[i][k - 1][0], lt = dp[i][k - 1][1];
                        int rf = dp[k + 1][j][0], rt = dp[k + 1][j][1];
                        if (s[k] == '&')
                        {
                            if (flag == 1)
                                cnt = (cnt + (lt * rt) % mod) % mod;
                            else
                                cnt = (cnt + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
                        }
                        else if (s[k] == '|')
                        {
                            if (flag == 1)
                                cnt = (cnt + (lt * rf) % mod + (lf * rt) % mod + (lt * rt) % mod) % mod;
                            else
                                cnt = (cnt + (lf * rf) % mod) % mod;
                        }

                        else
                        {
                            if (flag == 1)
                                cnt = (cnt + (lt * rf) % mod + (lf * rt) % mod) % mod;
                            else
                                cnt = (cnt + (lt * rt) % mod + (lf * rf) % mod) % mod;
                        }
                    }

                    dp[i][j][flag] = cnt % mod;
                }
            }
        }
    }

    dp[0][n - 1][1] %= mod;
    return dp[0][n - 1][1];
}
