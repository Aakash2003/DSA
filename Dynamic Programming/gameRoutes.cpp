#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (int)(1e5 + 5);
vector<int> g[N];
const int MOD = (int)(1e9 + 7);
ll dp[N];

void dfs(int s, int n)
{
    if (s == n)
    {
        dp[s] = 1;
        return;
    }
    else if (dp[s] > -1)
        return;
    else
    {
        dp[s] = 0;
        for (int v : g[s])
        {
            dfs(v, n);
            dp[s] += dp[v];
            dp[s] %= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
        dp[i] = -1;

    dfs(1, n);
    cout << dp[1];
    return 0;
}