#include <bits/stdc++.h>
using namespace std;

const int N = (int)(3e4 + 5);
vector<int> adjList[N];
bool visited[N];

void dfs(int node)
{
    visited[node] = true;
    for (int v : adjList[node])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    string ans[] = {"NO","YES"};
    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adjList[i].push_back(i + a);
    }

    dfs(1);

    cout<<ans[visited[t]];
}