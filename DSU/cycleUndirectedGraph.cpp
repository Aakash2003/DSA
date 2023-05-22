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

    int findRoot(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    bool combine(int u, int v, bool &ans)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);

        if (ru == rv)
        {
            ans = false;
            return;
        }

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
    int t;
    cin >> t;

    string ans[] = {"NO", "YES"};

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        pair<int, int> edges[m];
        for (int i = 0; i < m; i++)
            cin >> edges[i].first >> edges[i].second;

        DSU dsu = DSU(n);
        bool is_cycle = false;

        for (int i = 0; i < m; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            bool ans = true;
            dsu.combine(u, v, ans);
            
            if (ans == false)
                is_cycle = true;
        }

        cout << ans[is_cycle] << endl;
    }
}