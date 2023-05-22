#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int, int>> adjList[N + 1];
bool visited[N + 1];
int min_wt[N + 1];

void findMST(int n)
{
    set<pair<int,int>> s;
    s.insert({0,1});
    int mst_cost = 0;

    for(int i=1;i<=n;i++)
    {
        int node = s.begin()->second;
        int w = s.begin()->first;

        s.erase(s.begin());

        mst_cost += w;

        for(pair<int,int> e:adjList[node])
        {
            int new_node = e.first;
            int new_weight = e.second;

            if(!visited[new_node] && new_weight<min_wt[new_node])
            {
                s.erase({min_wt[new_node],new_node});
                min_wt[new_node] = new_weight;
                s.insert({min_wt[new_node],new_node});
            }
        }
    }

    cout<<"MST cost = "<<mst_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b, w;

    for (int i = 0; i <= n; i++)
        visited[i] = false, min_wt[i] = INT_MAX;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    findMST(n);
}