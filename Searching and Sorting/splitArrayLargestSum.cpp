#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int mid, int k)
{
    int n = nums.size();
    int cnt = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > mid)
            cnt++, sum = nums[i];

        if (nums[i] > mid || cnt > k)
            return false;
    }

    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int start = *max_element(nums.begin(), nums.end()), end = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;

    if (n == k)
        return start;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(nums, mid, k))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    int k;
    cin>>k;
    
    cout<<splitArray(nums,k)<<endl;
}