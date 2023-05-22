#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N + 1][N + 1];

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b, w;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dp[i][i] = 0;
            else
                dp[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        if (a != b)
            dp[a][b] = dp[b][a] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                if (dp[a][i] == INT_MAX || dp[i][b] == INT_MAX)
                    continue;
                    
                dp[a][b] = min(dp[a][b], dp[a][i] + dp[i][b]);
            }
        }
    }

    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
            cout << "distance between " << a << " and " << b << " = " << dp[a][b] << endl;
    }
}