#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int j = 0, i = 0, k = n - 1;

    while (i <= k)
    {
        if (nums[i] = 0)
        {
            swap(nums[i], nums[j]);
            i++, j++;
        }
        else if (nums[i] == 1)
            i++;
        else
        {
            swap(nums[i], nums[k]);
            k--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sortColors(nums);
}