#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int lower_bound(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }

    if (start < n && nums[start] < target)
        start++;

    return start;
}

int upper_bound(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] <= target)
            start = mid + 1;
        else
            end = mid;
    }

    if (start < n && nums[start] <= target)
        start++;

    return start;
}