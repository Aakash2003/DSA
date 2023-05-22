#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> nums)
{
    int n = nums.size();
    int maxi = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int maxSubarraySumCircular(vector<int> nums)
{
    int n = nums.size();
    int a, b, c;

    a = kadane(nums);
    b = 0;

    for (int i = 0; i < n; i++)
    {
        b += nums[i];
        nums[i] = -nums[i];
    }

    c = kadane(nums);
    if (b + c == 0)
        return a;
    else
        return max(a, b + c);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
        
    cout << maxSubarraySumCircular(nums);
}