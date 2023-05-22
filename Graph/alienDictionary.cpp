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

vector<char> findOrder(vector<string> &dict, int n, int k)
{
    vector<char> ans;
    vector<int> adjList[k];

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int n = s1.length(), m = s2.length();
        int mini = min(n, m);

        for (int i = 0; i < mini; i++)
        {
            if (s1[i] != s2[i])
            {
                adjList[s1[i] - 'a'].push_back(s2[i] - 'a');
                break;
            }
        }
    }

    vector<int> a = topo_sort(adjList, k);

    for (auto i : a)
        ans.push_back((char)i + 'a');

    return ans;
}