#include <bits/stdc++.h>
using namespace std;

vector<int> topo_sort(vector<int> adjList[], int n)
{
    vector<int> inDegree(n);
    for (int i = 0; i < n; i++)
    {
        for (int v : adjList[i])
            inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int v : adjList[node])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
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
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }

    vector<int> ans = topo_sort(adjList, n);

    for (auto i : ans)
        cout << i << " ";
}