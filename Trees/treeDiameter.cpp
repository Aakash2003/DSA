#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e4 + 5);
vector<int> tree[N];
int height[N];
int max_height[N];

int ans = 0;

void dfs(int s, int p, int ht = 0)
{
    height[s] = ht;
    max_height[s] = ht;
    int maxi = 0,second_maxi = 0;

    for(int v:tree[s])
    {
        if(v!=p)
        {
            dfs(v,s,ht+1);
            max_height[s] = max(max_height[s],max_height[v]);
            if(max_height[v]>maxi)
            {
                maxi = max_height[v];
                second_maxi = maxi;
            }
            else if(max_height[v]>second_maxi) second_maxi = max_height[v];
        }
    }

    int max_distance = max(0,max(maxi-ht,maxi+second_maxi-2*ht));
    ans = max(ans,max_distance);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            tree[i].clear();
            height[i] = max_height[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        ans = 0;
        dfs(1,0);

        cout<<ans<<endl;
    }
}