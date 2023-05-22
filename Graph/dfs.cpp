#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e5 + 5);
vector<int> adjList[N];
bool visited[N];

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int v : adjList[node])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1);
}