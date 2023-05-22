#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> nums)
{
    int n = nums.size();
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            flag = true;
        if (nums[i] < 1 || nums[i] > n)
            nums[i] = 1;
    }

    if (flag == false)
        return 1;

    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]);
        if (index - 1 >= 0 && index - 1 < n)
            nums[index - 1] = -abs(nums[index - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            return i + 1;
    }

    return n + 1;
}