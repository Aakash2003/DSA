#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src)
{
    vector<int> dist(n, 1e8);
    int m = edges.size();
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int src;
    cin >> src;

    vector<int> dist = bellmanFord(n, edges, src);

    for (int i = 0; i < n; i++)
        cout << "Egde " << i << " has a distance " << dist[i] << " from src" << endl;
}