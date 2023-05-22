#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char d[] = {'D', 'U', 'R', 'L'};

bool isValid(int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &arr)
{
    int n = arr.size();
    return (row >= 0 && row < n && col >= 0 && col < n && arr[row][col] == 1 && !visited[row][col]);
}

void allPossiblePaths(vector<vector<int>> &arr, vector<vector<bool>> &visited, vector<string> &all_paths, string &curr_path, int x, int y)
{
    if (arr[x][y] == 0)
        return;
    int n = arr.size();

    if (x == n - 1 && y == n - 1)
    {
        all_paths.push_back(curr_path);
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, visited, arr))
        {
            curr_path.push_back(d[i]);
            allPossiblePaths(arr, visited, all_paths, curr_path, newX, newY);
            curr_path.pop_back();
        }
    }

    visited[x][y] = false;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        vector<vector<bool>> visited(n, vector<bool>(n));
        vector<string> all_paths;
        string curr_path = "";
        allPossiblePaths(arr, visited, all_paths, curr_path, 0, 0);

        for (auto i : all_paths)
            cout << i << " ";
            
        cout << endl;
    }
}