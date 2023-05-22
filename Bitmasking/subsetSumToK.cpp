#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(int x)
{
    return 1 << x;
}

vector<vector<int>> findSubsetsSumToK(vector<int> arr, int k)
{
    vector<vector<int>> ans;
    int n = arr.size();
    for (int mask = 0; mask < powerOfTwo(n); mask++)
    {
        int sum = 0;
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & powerOfTwo(i))
            {
                sum += arr[i];
                subset.push_back(arr[i]);
            }
        }

        if (sum == k)
            ans.push_back(subset);
    }

    return ans;
}

