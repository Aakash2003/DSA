#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[],vector<int> &visited,int node,int parent,bool &ans)
{
    visited[node] = true;
    for(auto i:adjList[node])
    {
        if(!visited[i])
        {
            dfs(adjList,visited,i,node,ans);
            if(ans==true) return;
        }
        else if(i!=parent) 
        {
            ans = true;
            return;
        }
    }
}

bool isCycle(vector<int> adjList[],int n)
{
    bool ans = false;
    vector<int> visited(n);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(adjList,visited,i,-1,ans);
            if(ans==true) return true;
        }
    }

    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> adjList[n];
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    string ans[] = {"No","Yes"};
    cout<<ans[isCycle(adjList,n)]<<endl;
}