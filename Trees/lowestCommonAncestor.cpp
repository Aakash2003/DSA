#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LGN = 20;
vector<int> g[N];
int dp[LGN][N];
int heights[N];

int powerOfTwo(int x)
{
    return 1 << x;
}

void dfs(int s, int p, int h = 0)
{
    heights[s] = h;
    dp[0][s] = p;
    for (int i = 1; i < LGN; i++)
        dp[i][s] = dp[i - 1][dp[i - 1][s]];

    for (int v : g[s])
    {
        if (v != p)
            dfs(v, s, h + 1);
    }
}

int lift(int u, int h)
{
    for (int i = 0; i < LGN; i++)
    {
        if (h & powerOfTwo(i))
            u = dp[i][u];
    }

    return u;
}

int lca(int u, int v)
{
    if (heights[v] > heights[u])
        swap(u, v);

    u = lift(u, heights[u] - heights[v]);
    if (u == v)
        return u;

    for (int i = LGN - 1; i >= 0; i--)
    {
        if (dp[i][u] != dp[i][v])
        {
            u = dp[i][u];
            v = dp[i][v];
        }
    }

    return dp[0][u];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < N; i++)
        {
            heights[i] = 0;
            g[i].clear();
            for (int j = 0; j < LGN; j++)
                dp[j][i] = 0;
        }

        int n;
        cin >> n;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v), g[v].push_back(u);
        }

        dfs(1, 0);

        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}