#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> subtree_size;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            subtree_size.push_back(1);
        }
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

    bool combine(int u, int v)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);

        if (ru == rv)
            return false;

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

        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    pair<int, int> edges[n - 1];
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;

    DSU dsu = DSU(n);

    vector<int> cycle_edges;
    for(int i=0;i<n-1;i++)
    {
        bool is_added = dsu.combine(edges[i].first,edges[i].second);
        if(is_added==false) cycle_edges.push_back(i);
    }

    set<int> roots;

    for(int i=1;i<=n;i++)
    {
        int root_i = dsu.findRoot(i);
        roots.insert(root_i);
    }

    cout<<cycle_edges.size()<<endl;

    if(cycle_edges.size()>0)
    {
        auto itr = roots.begin();
        itr++;

        for(int i=0;i<cycle_edges.size();i++)
        {
            int index = cycle_edges[i];
            cout<<edges[index].first<<" "<<edges[index].second<<" "<<*itr<<" "<<*roots.begin()<<endl;
            itr++;
        }
    }

    return 0;
}