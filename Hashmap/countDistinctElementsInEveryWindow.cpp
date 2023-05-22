#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> mp;
    vector<int> ans;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k - 1)
            mp[nums[i]]++;
        else
        {
            mp[nums[i]]++;
            ans.push_back(mp.size());

            int freq = mp[nums[j]];
            if (freq == 1)
                mp.erase(nums[j]);
            else
                mp[nums[j]]--;

            j++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    vector<int> ans = countDistinct(nums, k);
    for (auto i : ans)
        cout << i << " ";
}