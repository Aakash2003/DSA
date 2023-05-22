#include <bits/stdc++.h>
using namespace std;

int twoCitySchedCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    int mini = 0;
    vector<int> diff;

    for (int i = 0; i < n; i++)
    {
        mini += costs[i][0];
        diff.push_back(costs[i][1] - costs[i][0]);
    }

    sort(diff.begin(), diff.end());

    int index = n / 2;
    for (int i = 0; i < index; i++)
        mini += diff[i];

    return mini;
}
