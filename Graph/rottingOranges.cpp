#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0)
        return 0;

    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto itr = q.front();
            int x = itr.first, y = itr.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 1)
                {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                    fresh--;
                }
            }
        }

        time++;
        if (fresh == 0)
            return time;
    }

    return -1;
}