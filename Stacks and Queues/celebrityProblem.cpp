#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() >= 2)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (matrix[a][b] == 0)
            s.push(a);
        else
            s.push(b);
    }

    int potential_celebrity = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
        if (i != potential_celebrity)
        {
            if (matrix[i][potential_celebrity] == 0 || matrix[potential_celebrity][i] == 1)
                return -1;
        }
    }

    return potential_celebrity;
}