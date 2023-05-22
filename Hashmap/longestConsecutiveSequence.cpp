#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    int mini = INT_MAX, maxi = INT_MIN;

    map<int, bool> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = true;
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    int cnt = 0;
    int ans = 0;

    for (int i = mini; i <= maxi; i++)
    {
        if (mp.count(i) > 0)
            cnt++;
        else
            cnt = 0;

        ans = max(ans, cnt);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << longestConsecutive(nums) << endl;
}
