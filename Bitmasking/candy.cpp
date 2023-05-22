#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(int x)
{
    return (1 << x);
}

int numWays(int n, vector<vector<int>> &likes)
{
    vector<vector<int>> dp(n + 1, vector<int>(powerOfTwo(n)));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < powerOfTwo(n); mask++)
        {
            for (int j = 0; j < n; j++)
            {
                if (likes[i][j] > 0 && (mask & powerOfTwo(j)))
                    dp[i][mask] += dp[i - 1][mask ^ powerOfTwo(j)];
            }
        }
    }

    return dp[n][powerOfTwo(n) - 1];
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> likes(n + 1, vector<int>(n));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> likes[i][j];
        }

        cout << numWays(n, likes) << endl;
    }

    return 0;
}