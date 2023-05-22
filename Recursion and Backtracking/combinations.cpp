#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void combinations(int index, int n, int count, int k, vector<int> &output)
{
    if (index >= n)
    {
        if (count == k)
            ans.push_back(output);

        return;
    }

    output.push_back(index);
    combinations(index + 1, n, count + 1, k, output);
    output.pop_back();

    combinations(index + 1, n, count, k, output);
}