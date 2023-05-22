#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

double knightProbability(int n, int k, int row, int column)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2)));
    dp[row][column][0] = 1;

    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            for(int i=0;i<8;i++)
            {
                int newX = x+dx[i];
                int newY = y+dy[i];

                if(newX>=0 && newX<n && newY>=0 && newY<n) dp[newX][newY][1] += dp[x][y][0]/8.0;
            }
        }
    }
}