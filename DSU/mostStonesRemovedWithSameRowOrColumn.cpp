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

int removeStones(vector<vector<int>> &stones)
{
    int size = stones.size();
    int n = 0, m = 0;
    for (int i = 0; i < size; i++)
    {
        n = max(n, stones[i][0]);
        m = max(m, stones[i][1]);
    }

    DSU dsu = DSU(n + m + 1);
    map<int, int> uniqueStone;

    for (int i = 0; i < size; i++)
    {
        int nodeRow = stones[i][0];
        int nodeCol = n + stones[i][1] + 1;
        dsu.combine(nodeRow, nodeCol);
        uniqueStone[nodeRow] = 1;
        uniqueStone[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto i : uniqueStone)
    {
        if (dsu.parent[i.first]==i.first) cnt++;
    }

    return n-cnt;
}

int main()
{
}