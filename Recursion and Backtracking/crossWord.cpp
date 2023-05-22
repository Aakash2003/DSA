#include <bits/stdc++.h>
using namespace std;

const int n = 10;

bool isSafe_horizontal(vector<string> matrix, string word, int row, int col)
{
    int x = word.length();
    if (col - 1 >= 0 && matrix[row][col - 1] != '+')
        return false;
    else if (col + x < n && matrix[row][col + x] != '+')
        return false;

    for (int a = 0; a < x; a++)
    {
        if (col + a >= n)
            return false;

        if (matrix[row][col + a] == '-' || matrix[row][col + a] == word[a])
            continue;
        else
            return false;
    }

    return true;
}

bool isSafe_vertical(vector<string> matrix, string word, int row, int col)
{
    int x = word.length();
    if (row - 1 >= 0 && matrix[row - 1][col] != '+')
        return false;
    else if (row + x < n && matrix[row + x][col] != '+')
        return false;

    for (int a = 0; a < x; a++)
    {
        if (row + a >= n)
            return false;

        if (matrix[row + a][col] == '-' || matrix[row + a][col] == word[a])
            continue;
        else
            return false;
    }

    return true;
}

vector<bool> place_horizontal(vector<string> matrix, string word, int row, int col)
{
    vector<bool> we_placed;
    int x = word.length();

    for (int a = 0; a < x; a++)
    {
        if (matrix[row][col + a] == '-')
        {
            matrix[row][col + a] = word[a];
            we_placed[a] = true;
        }
    }

    return we_placed;
}

vector<bool> place_vertical(vector<string> matrix, string word, int row, int col)
{
    vector<bool> we_placed;
    int x = word.length();

    for (int a = 0; a < x; a++)
    {
        if (matrix[row + a][col] == '-')
        {
            matrix[row + a][col] = word[a];
            we_placed[a] = true;
        }
    }

    return we_placed;
}

void unplace_horizontal(vector<string> matrix, vector<bool> we_placed, int row, int col)
{
    int x = we_placed.size();
    for (int a = 0; a < x; a++)
    {
        if (we_placed[a] == true)
            matrix[row][col + a] = '-';
    }
}

void unplace_vertical(vector<string> matrix, vector<bool> we_placed, int row, int col)
{
    int x = we_placed.size();
    for (int a = 0; a < x; a++)
    {
        if (we_placed[a] == true)
            matrix[row + a][col] = '-';
    }
}

void print(vector<string> matrix)
{
    for (int i = 0; i < n; i++)
        cout << matrix[i] << endl;
}

void solve(vector<string> matrix, vector<string> words, int index)
{
    int m = words.size();
    if (index >= m)
    {
        print(matrix);
        return;
    }

    string word = words[index];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '-' || matrix[i][j] == word[0])
            {
                if (isSafe_horizontal(matrix, word, i, j))
                {
                    vector<bool> we_placed = place_horizontal(matrix, word, i, j);
                    solve(matrix, words, index + 1);
                    unplace_horizontal(matrix, we_placed, i, j);
                }

                if (isSafe_vertical(matrix, word, i, j))
                {
                    vector<bool> we_placed = place_vertical(matrix, word, i, j);
                    solve(matrix, words, index + 1);
                    unplace_vertical(matrix, we_placed, i, j);
                }
            }
        }
    }
}

int main()
{
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        matrix[i] = s;
    }

    int m;
    cin >> m;
    vector<string> words(m);

    for (int i = 0; i < m; i++)
        cin >> words[i];

    solve(matrix, words, 0);

    return 0;
}