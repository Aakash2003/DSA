#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<int> adjList[], int src, int n)
{
    vector<int> visited(n);
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int v : adjList[node])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int src = 0;
    vector<int> bfs = bfsOfGraph(adjList, src, n);

    for (auto i : bfs)
        cout << i << " ";
}