#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int par, vector<bool> &visited, vector<int> &in, vector<int> &low, vector<int> adjList[], vector<bool> &isArticulationPoint)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    int cnt = 0;

    for (int v : adjList[node])
    {
        if (v == par)
            continue;

        if (!visited[v])
        {
            dfs(v, node, visited, in, low, adjList, isArticulationPoint);
            if (low[v] >= in[node] && par != -1)
                isArticulationPoint[node] = true;

            low[node] = min(low[node], low[v]);
            cnt++;
        }
        else
            low[node] = min(low[node], in[v]);
    }

    if (cnt > 1 && par == -1)
        isArticulationPoint[node] = true;
}

vector<int> articulationPoints(int n, vector<int> adjList[])
{
    vector<bool> visited(n);
    vector<int> in(n), low(n);
    vector<bool> isArticulationPoint(n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, -1, visited, in, low, adjList, isArticulationPoint);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (isArticulationPoint[i] == true)
            ans.push_back(i);
    }

    if (ans.size() == 0)
        return {-1};
    else
        return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n];

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> ans = articulationPoints(n, adjList);

    for (auto i : ans)
        cout << i << " ";
}