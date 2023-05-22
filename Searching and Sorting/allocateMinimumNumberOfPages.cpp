#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int mid, int m)
{
    int n = arr.size();
    int cnt = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
            cnt++, sum = arr[i];

        if (arr[i] > mid || cnt > m)
            return false;
    }

    return true;
}

int findPages(vector<int> &arr, int m)
{
    int n = arr.size();
    if (n < m)
        return -1;

    int start = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, mid, m))
            ans = mid, end = mid - 1;
        else
            start = mid + 1;
    }

    return ans;
}