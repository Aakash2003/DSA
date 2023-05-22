#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dist(n, vector<int>(m));
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
            else
                dist[i][j] = -1;
        }
    }

    while (!q.empty())
    {
        auto itr = q.front();
        int x = itr.first,y = itr.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY]<0)
            {
                q.push({newX, newY});
                dist[newX][newY] = dist[x][y] + 1;
            }
        }
    }

    return dist;
}