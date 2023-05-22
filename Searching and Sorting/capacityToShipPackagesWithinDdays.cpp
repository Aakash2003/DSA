#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &weights, int mid, int days)
{
    int n = weights.size();
    int cnt = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += weights[i];

        if (sum > mid)
        {
            cnt++;
            sum = weights[i];
        }

        if (weights[i] > mid || cnt > days)
            return false;
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int start = *max_element(weights.begin(), weights.end()), end = accumulate(weights.begin(), weights.end(), 0);
    int ans = 0;

    if (n == days)
        return start;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(weights, mid, days))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}