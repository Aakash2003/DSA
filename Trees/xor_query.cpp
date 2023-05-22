#include<bits/stdc++.h>
using namespace std;

const int N = (int)(1e5+5);
vector<int> tree[N];
int subtree_xor[N];

void dfs(int s,int p)
{
    subtree_xor[s] = s;

    for(int v:tree[s])
    {
        if(v!=p)
        {
            dfs(v,s);
            subtree_xor[s] ^= subtree_xor[v];
        }
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        for(int i=0;i<=n;i++)
        {
            tree[i].clear();
            subtree_xor[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(0,0);

        while(q--)
        {
            int u;
            cin>>u;
            cout<<subtree_xor[u]<<endl;
        }
    }

    return 0;
}