#include <bits/stdc++.h>
using namespace std;

int superEggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int eggs = 1; eggs <= n; eggs++)
    {
        for (int floor = 1; floor <= k; floor++)
        {
            if (eggs == 1)
                dp[eggs][floor] = floor;
            else if (floor == 1)
                dp[eggs][floor] = 1;
            else
            {
                int mini = INT_MAX;
                for (int u = floor - 1, v = 0; u >= 0; u--, v++)
                {
                    int maxVal = max(dp[eggs][u], dp[eggs - 1][v]);
                    mini = min(mini, maxVal);
                }

                if (mini != INT_MAX)
                    dp[eggs][floor] = mini + 1;
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << superEggDrop(n, k) << endl;
}