#include <bits/stdc++.h>
#define n 9
using namespace std;

vector<vector<char>> ans;

bool isValid(vector<vector<char>> &board, char val, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][y] == val)
            return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (board[x][j] == val)
            return false;
    }

    int s = n / 3;
    int smallX = x / s * s;
    int smallY = y / s * s;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (board[smallX + i][smallY + j] == val)
                return false;
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board, int x, int y)
{
    int newX = 0, newY = 0;
    if (x >= n)
    {
        ans = board;
        return;
    }

    if (y == n - 1)
        newX = x + 1, newY = 0;
    else
        newX = x, newY = y + 1;

    if (board[x][y] != '.')
        solveSudoku(board, newX, newY);
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (isValid(board, i + '0', x, y))
            {
                board[x][y] = i + '0';
                solveSudoku(board, newX, newY);
                board[x][y] = '.';
            }
        }
    }
}

void solveSudoku(vector<vector<char>> &board)
{
    int x = 0, y = 0;
    solveSudoku(board, x, y);
    board = ans;
}

