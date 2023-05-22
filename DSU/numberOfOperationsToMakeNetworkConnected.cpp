#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> subtree_size;
    int N;

    DSU(int n)
    {
        N = n;
        parent = vector<int>(n, 0);
        subtree_size = vector<int>(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
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

        if (subtree_size[ru] > subtree_size[rv])
        {
            parent[rv] = ru;
            subtree_size[ru] += subtree_size[rv];
        }
        else
        {
            parent[ru] = rv;
            subtree_size[rv] += subtree_size[ru];
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m);
    for (int i = 0; i < m; i++)
        cin >> connections[i][0] >> connections[i][1];

    DSU dsu = DSU(n);
    int extra_edges = 0;

    for (int i = 0; i < m; i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        if (dsu.findRoot(u) == dsu.findRoot(v))
            extra_edges++;
        else
            dsu.combine(u, v);
    }

    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu.parent[i] == i)
            components++;
    }

    int ans = components - 1;
    if (extra_edges >= ans)
        return ans;
    else
        return -1;
}