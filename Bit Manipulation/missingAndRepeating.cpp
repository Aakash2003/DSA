#include <bits/stdc++.h>
using namespace std;

vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int n = nums.size();
    int result_xor = 0;

    for (int i = 0; i < n; i++)
    {
        result_xor ^= nums[i];
        result_xor ^= (i + 1);
    }

    int right_set_bit = result_xor & (~(result_xor - 1));
    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] & right_set_bit)
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & right_set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }

    bool is_x_missing = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            is_x_missing = false;
            break;
        }
    }

    if (is_x_missing == true)
        return {x, y};
    else
        return {y, x};
}