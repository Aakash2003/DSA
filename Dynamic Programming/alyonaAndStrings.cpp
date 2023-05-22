#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, K;
    cin >> n >> m >> K;

    string s, t;
    cin >> s >> t;

    s = '#' + s;
    t = '@' + t;

    int dp[n + 1][m + 1][K + 1][2];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                for (int flag = 0; flag < 2; flag++)
                {
                    dp[i][j][k][flag] = INT_MIN;

                    if (k == 0)
                        dp[i][j][k][flag] = 0;
                    if (i == 0 || j == 0)
                    {
                        if (k == 1 && flag == 1)
                            dp[i][j][k][flag] = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                if (s[i] == t[j])
                {
                    dp[i][j][k][0] = max({1 + dp[i - 1][j - 1][k][1], dp[i - 1][j][k][0], dp[i][j - 1][k][0]});
                    dp[i][j][k][1] = max({1 + dp[i - 1][j - 1][k][1], dp[i][j][k - 1][0]});
                }
                else
                {
                    dp[i][j][k][0] = max({dp[i - 1][j][k][0], dp[i][j - 1][k][0]});
                    dp[i][j][k][1] = dp[i][j][k - 1][0];
                }
            }
        }
    }

    cout << max({dp[n][m][K][0], dp[n][m][K][1]});
    return 0;
}