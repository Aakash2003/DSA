#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return {-1, -1};

    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    if (left >= n)
        return {-1, -1};

    if (nums[left] == target)
        return {left, right - 1};
    else
        return {-1, -1};
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    int target;
    cin >> target;

    vector<int> ans = searchRange(nums, target);
    for (auto i : ans)
        cout << i << " ";
}