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

int main()
{
    int n;
    cin >> n;
    DSU dsu = DSU(n);

    int q;
    cin >> q;

    while (q--)
    {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) dsu.combine(u, v);
        else
        {
            int ru = dsu.findRoot(u);
            int rv = dsu.findRoot(v);

            if(ru==rv) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}