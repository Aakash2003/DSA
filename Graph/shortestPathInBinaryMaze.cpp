#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dest)
{
    if (grid[src.first][src.second] == 0)
        return -1;
    else if (src == dest)
        return 0;

    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[src.first][src.second] = 0;
    q.push({0, {src.first, src.second}});

    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        int d = itr.first;
        int x = itr.second.first;
        int y = itr.second.second;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && dist[newX][newY] > d + 1)
            {
                dist[newX][newY] = d + 1;
                if (newX == dest.first && newY == dest.second)
                    return d + 1;
                q.push({d + 1, {newX, newY}});
            }
        }
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    pair<int, int> src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;

    cout << shortestPath(grid, src, dest);
}