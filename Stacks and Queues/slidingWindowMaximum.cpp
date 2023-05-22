#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementRight(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] >= nums[s.top()])
            s.pop();

        if (s.empty())
            ans[i] = n;
        else
            ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    vector<int> right = nextGreaterElementRight(nums);

    int j = 0;
    for (int i = 0; i <= n - k; i++)
    {
        if (j < i)
            j = i;
            
        while (right[j] < i + k)
            j = right[j];

        ans.push_back(nums[j]);
    }

    return ans;
}