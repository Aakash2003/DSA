#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bridges;
int timer = 0;

void dfs(int node, int par, vector<bool> &visited, vector<int> adjList[], vector<int> &in, vector<int> &low)
{
    visited[node] = true;
    in[node] = low[node] = timer++;

    for (int v : adjList[node])
    {
        if (v == par)
            continue;

        if (!visited[v])
        {
            dfs(v, node, visited, adjList, in, low);
            low[node] = min(low[node], low[v]);
            if (low[v] > in[node])
                bridges.push_back({v, node});
        }
        else
            low[node] = min(low[node], in[v]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    int m = connections.size();
    vector<int> adjList[n];
    for (int i = 0; i < m; i++)
    {
        int a = connections[i][0], b = connections[i][1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<int> in(n), low(n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, -1, visited, adjList, in, low);
    }

    return bridges;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m, vector<int>(2));

    for (int i = 0; i < m; i++)
        cin >> connections[i][0] >> connections[i][1];

    for (auto i : bridges)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}