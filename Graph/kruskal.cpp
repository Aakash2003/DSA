#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> subtree_size;
    int N;

public:
    DSU(int n)
    {
        N = n;
        parent = vector<int>(n + 1, 0);
        subtree_size = vector<int>(n + 1, 1);

        for (int i = 1; i <= n; i++)
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

int spanningTree(vector<pair<int, int>> adjList[], int n)
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for (auto v : adjList[i])
        {
            int node = i;
            int adjNode = v.first;
            int wt = v.second;

            edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(),edges.end());
    int mst_cost = 0;

    DSU dsu = DSU(n);

    for(auto i:edges)
    {
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;

        if(dsu.findRoot(u)!=dsu.findRoot(v))
        {
            mst_cost+=wt;
            dsu.combine(u,v);
        }
    }

    return mst_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adjList[n];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    cout << spanningTree(adjList, n) << endl;
}