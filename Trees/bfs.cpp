#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e5 + 5);
vector<int> tree[N];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vector<bool> visited(N);
    visited[root] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v : tree[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v), tree[v].push_back(u);
    }

    bfs(1);
    cout << endl;
}