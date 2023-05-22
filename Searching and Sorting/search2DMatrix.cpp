#include <bits/stdc++.h>
using namespace std;

int row_select(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target)
            return mid;
        else if (target > matrix[mid][m - 1])
            start = mid + 1;
        else if (target < matrix[mid][0])
            end = mid - 1;
    }

    return -1;
}

bool binary_search(vector<vector<int>> &matrix, int r, int target)
{
    int m = matrix[0].size();
    int start = 0, end = m - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (matrix[r][mid] == target)
            return true;
        else if (matrix[r][mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = row_select(matrix, target);

    if (r == -1)
        return false;
    else
        return binary_search(matrix, r, target);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    int target;
    cin >> target;

    string ans[] = {"No", "Yes"};
    cout << ans[searchMatrix(matrix, target)] << endl;
}