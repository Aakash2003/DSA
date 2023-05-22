#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5;
vector<int> adjList[N + 1];
int color[N + 1];
bool visited[N + 1];

bool dfs(int node, int col)
{
    visited[node] = true;
    color[node] = col;

    for (int v : adjList[node])
    {
        if (!visited[v])
        {
            bool ans = dfs(node, col ^ 1);
            if (ans == true)
                return true;
        }
        else
        {
            if (color[v] == col)
                return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(i, 0);
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "The given graph is not bipartite" << endl;
    else
        cout << "The given graph is bipartite" << endl;
}