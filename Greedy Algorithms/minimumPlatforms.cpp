#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int cnt = 0, platforms = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
            cnt++, i++;
        else
            cnt--, j++;

        platforms = max(platforms, cnt);
    }

    return platforms;
}