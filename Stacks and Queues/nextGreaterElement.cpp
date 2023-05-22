#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterRight(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] >= s.top())
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
            
        s.push(nums[i]);
    }

    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size(), m = queries.size();
    vector<int> ans(m);
    vector<int> right = nextGreaterRight(nums);

    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[nums[i]] = right[i];
    for (int i = 0; i < m; i++)
        ans[i] = mp[queries[i]];

    return ans;
}
