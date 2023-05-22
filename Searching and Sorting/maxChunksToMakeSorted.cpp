#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();
    vector<int> mini(n + 1);
    mini[n] = INT_MAX;

    for (int i = n - 1; i >= 0; i--)
        mini[i] = min(mini[i + 1], arr[i]);

    int maxi = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        if (maxi <= mini[i + 1])
            cnt++;
    }

    return cnt;
}

int main()
{
}