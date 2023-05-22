#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] > nums[end])
            start = mid + 1;
        else if (nums[mid] == nums[end])
            end--;
        else
            end = mid;
    }

    return nums[start];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << findMin(nums) << endl;
}