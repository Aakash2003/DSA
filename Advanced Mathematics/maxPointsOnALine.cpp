#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    if (n < 3)
        return n;

    int maxi = 0;
    
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    cout << maxPoints(points) << endl;
}