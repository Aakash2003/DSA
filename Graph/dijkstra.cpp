#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<pair<int, int>> adjList[], int src)
{
    set<pair<int, int>> s;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto itr = *s.begin();
        int d = itr.first;
        int node = itr.second;
        s.erase(itr);

        for (auto i : adjList[node])
        {
            int adjNode = i.first;
            int edgeWeight = i.second;

            if (d + edgeWeight < dist[adjNode])
            {
                if (dist[adjNode] != INT_MAX)
                    s.erase({dist[adjNode], adjNode});
                dist[adjNode] = d + edgeWeight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<pair<int, int>> adjList[n];

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    vector<int> ans = dijkstra(n, adjList, src);

    for (auto i : ans)
        cout << i << " ";
}