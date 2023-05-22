#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)(1e5+5);

class DSU
{
    int parent[MAX];
    int subtree[MAX];

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            subtree[i] = 1;
        }
    }

    int findRoot(int u)
    {
        while (u != parent[u])
        {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }

    void combine(int u, int v)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);

        if (ru == rv)
            return;
        else if (subtree[ru] > subtree[rv])
        {
            parent[rv] = ru;
            subtree[ru] += subtree[rv];
        }
        else
        {
            parent[ru] = rv;
            subtree[rv] += subtree[ru];
        }
    }

    long long getSize(int u)
    {
        int ru = findRoot(u);
        return subtree[ru];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, pair<int, int>> edges[m];
    const long long mod = 1000000000;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }

    sort(edges, edges + m);
    long long csum[m];
    csum[0] = edges[0].first;

    for (int i = 0; i < m; i++)
        csum[i] = csum[i - 1] + 1LL*edges[i].first;

    DSU dsu = DSU(n);
    long long ans = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        int u = edges[i].second.first, v = edges[i].second.second;
        int ru = dsu.findRoot(u), rv = dsu.findRoot(v);
        if(ru==rv) continue;

        long long curr = ((dsu.getSize(ru)*dsu.getSize(rv)) % mod)*csum[i];
        curr %= mod;
        ans += curr;
        ans %= mod;
        dsu.combine(u,v);
    }

    cout<<ans;
    return 0;
}