#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &a, int x, int y, int xi, int yi)
{
    int n = grid.size(), m = grid[0].size();
    visited[x][y] = true;
    a.push_back({x-xi,y-yi});

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 1)
            dfs(grid, visited, a, newX, newY, xi, yi);
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> a;
                dfs(grid, visited, a, i, j, i, j);
                s.insert(a);
            }
        }
    }

    return s.size();
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>grid[i][j];
    }

    cout<<countDistinctIslands(grid)<<endl;
}