#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (int)(1e5 + 5);
vector<int> tree[N];

void dfs(int s, int p)
{
    cout << s << " ";
    for (int v : tree[s])
    {
        if (v != p)
            dfs(v, s);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    cout << endl;
}