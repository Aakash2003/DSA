#include <bits/stdc++.h>
using namespace std;

int grid[16][16];

bool isValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > 15 || y > 15)
        return false;
    return true;
}

int f(int x, int y)
{
    if (grid[x][y] != -1)
        return grid[x][y];
    else
    {
        bool isWin = false;
        if (isValid(x - 1, y - 2))
        {
            if (f(x - 1, y - 2) == 0)
                isWin = true;
        }

        if (isValid(x + 1, y - 2))
        {
            if (f(x + 1, y - 2) == 0)
                isWin = true;
        }

        if (isValid(x - 2, y - 1))
        {
            if (f(x - 2, y - 1) == 0)
                isWin = true;
        }

        if (isValid(x - 2, y + 1))
        {
            if (f(x - 2, y + 1) == 0)
                isWin = true;
        }

        if (isWin)
            grid[x][y] = 1;
        else
            grid[x][y] = 0;
            
        return grid[x][y];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i <= 15; i++)
        {
            for (int j = 0; j <= 15; j++)
                grid[i][j] = -1;
        }

        grid[1][1] = grid[1][2] = grid[2][1] = grid[2][2] = 0;
        if (f(x, y) == 0)
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
}