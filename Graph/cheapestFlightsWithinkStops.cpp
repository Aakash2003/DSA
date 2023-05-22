#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dest, int k)
{
    int m = flights.size();
    vector<pair<int, int>> adjList[n];

    for (int i = 0; i < m; i++)
        adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        int stops = itr.first;
        int node = itr.second.first;
        int cost = itr.second.second;

        if (stops > k)
            continue;
        for (pair<int, int> v : adjList[node])
        {
            int adjNode = v.first;
            int edgeWeight = v.second;

            if (cost + edgeWeight < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + edgeWeight;
                q.push({stops + 1, {adjNode, cost + edgeWeight}});
            }
        }
    }

    if (dist[dest] == INT_MAX)
        return -1;
    else
        return dist[dest];
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;
    vector<vector<int>> flights(m, vector<int>(3));

    for (int i = 0; i < m; i++)
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];

    int src, dest, k;
    cin >> src >> dest >> k;

    cout << findCheapestPrice(n, flights, src, dest, k) << endl;
}