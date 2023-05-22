#include<bits/stdc++.h>
using namespace std;

const int N = (int)1e5;
vector<int> adjList[N+1];
int in[N+1],low[N+1];
int timer = 0;
bool visited[N+1];

void dfs(int node,int par)
{
    in[node] = low[node] = timer++;
    visited[node] = true;

    for(int v:adjList[node])
    {
        if(v==par) continue;

        if(!visited[v])
        {
            dfs(v,node);
            if(low[v]>in[node]) cout<<node<<" -> "<<v<<" is a bridge"<<endl;
            low[node] = min(low[node],low[v]);
        }
        else low[node] = min(low[node],in[v]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1,-1);
}