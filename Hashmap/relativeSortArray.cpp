#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> mp;
    int curr = 0;

    for (auto i : arr1)
        mp[i]++;

    for (auto i : arr2)
    {
        while (mp[i] > 0)
        {
            arr1[curr] = i;
            curr++, mp[i]--;
        }
    }

    for (auto i : mp)
    {
        while (i.second > 0)
        {
            arr1[curr] = i.first;
            curr++, i.second--;
        }
    }

    return arr1;
}