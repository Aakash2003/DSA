#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adjList[numCourses];
    int m = prerequisites.size();

    for (int i = 0; i < m; i++)
        adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);

    vector<int> inDegree(numCourses);
    for (int i = 0; i < numCourses; i++)
    {
        for (int v : adjList[i])
            inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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

    if(ans.size()==numCourses) return true;
    else return false;
}

int main()
{
}