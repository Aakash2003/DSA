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

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    DSU dsu = DSU(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1)
                dsu.combine(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu.parent[i] == i) cnt++;
    }

    return cnt;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> isConnected(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>isConnected[i][j];
    }

    cout<<findCircleNum(isConnected)<<endl;
}