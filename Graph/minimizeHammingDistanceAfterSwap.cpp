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

int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
{
    int n = source.size();
    int m = allowedSwaps.size();

    DSU dsu = DSU(n);

    for (int i = 0; i < m; i++)
    {
        int a = allowedSwaps[i][0];
        int b = allowedSwaps[i][1];

        if (dsu.findRoot(a) != dsu.findRoot(b))
            dsu.combine(a, b);
    }

    map<int,map<int,int>> mp;
    map<int,int> freq;

    for(int i=0;i<n;i++)
    {
        int root = dsu.findRoot(i);
        int num = source[i];

        if(mp.count(root)==0) mp.insert({root,freq});

        freq = mp[root];
        freq[num]++;
    }

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int root = dsu.findRoot(i);
        int num = target[i];

        map<int,int> s = mp[root];
        if(s.count(num)==0)
        {
            cnt++;
            continue;
        }

    }
}

int main()
{
}
