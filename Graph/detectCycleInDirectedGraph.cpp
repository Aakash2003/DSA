#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> *adjList, vector<int> &visited, vector<int> &path_visited)
{
    visited[node] = 1;
    path_visited[node] = 1;

    for (int v : adjList[node])
    {
        if (!visited[v])
        {
            if (dfs(v, adjList, visited, path_visited))
                return true;
        }
        else if (path_visited[v])
            return true;
    }

    path_visited[node] = 0;
    return false;
}

bool isCyclic(vector<int> adjList[], int n)
{
    vector<int> visited(n);
    vector<int> path_visited(n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adjList, visited, path_visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }

    string ans[] = {"false", "true"};
    cout << ans[isCyclic(adjList, n)] << endl;
}