#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(vector<vector<char>> &board, string &word, vector<vector<int>> &visited, int x, int y, int index, bool &ans)
{
    int length = word.length();
    if (index >= length)
    {
        ans = true;
        return;
    }

    visited[x][y] = 1;
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && board[newX][newY] == word[index])
            dfs(board, word, visited, newX, newY, index + 1, ans);
    }

    visited[x][y] = false;
}

bool exist(vector<vector<char>> &board, string &word)
{
    bool ans = false;
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                dfs(board, word, visited, i, j, 1, ans);
                if (ans == true)
                    break;
            }
        }

        if (ans == true)
            break;
    }

    return ans;
}