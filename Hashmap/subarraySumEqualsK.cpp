#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> mp;
    mp[0] = 1;

    int curr_sum = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];
        if (mp.count(curr_sum - k) != 0)
            total += mp[curr_sum - k];
            
        mp[curr_sum]++;
    }

    return total;
}