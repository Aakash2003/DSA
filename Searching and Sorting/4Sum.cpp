#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i <= n - 4; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j <= n - 3; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;
            int start = j + 1, end = n - 1;
            while (start < end)
            {
                ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[start] + (ll)nums[end];
                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                    start++, end--;

                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                }
            }
        }
    }

    return ans;
}