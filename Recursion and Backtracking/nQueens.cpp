#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void addSolution(vector<vector<int>> &chessBoard)
{
    vector<int> state;
    for (auto i : chessBoard)
    {
        for (auto j : i)
            state.push_back(j);
    }

    ans.push_back(state);
    return;
}

bool isSafe(vector<vector<int>> &chessBoard, int row, int col)
{
    int n = chessBoard.size();

    for (int i = 0; i < col; i++)
    {
        if (chessBoard[row][i] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chessBoard[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (chessBoard[i][j] == 1)
            return false;
    }

    return true;
}

void nQueenHelper(vector<vector<int>> &chessBoard, int col)
{
    int n = chessBoard.size();
    if (col >= n)
    {
        addSolution(chessBoard);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(chessBoard,row,col))
        {
            chessBoard[row][col] = 1;
            nQueenHelper(chessBoard,col+1);
            chessBoard[row][col] = 0;
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));

    nQueenHelper(chessBoard, 0);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}