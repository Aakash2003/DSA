#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void subsetSumToK(vector<int> &nums, int target, int index, vector<int> &output)
{
    int n = nums.size();
    if (index >= n)
    {
        if (target == 0)
            ans.push_back(output);
        return;
    }

    output.push_back(nums[index]);
    subsetSumToK(nums, target - nums[index], index + 1, output);
    output.pop_back();

    subsetSumToK(nums, target, index + 1, output);
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

    vector<int> output;
    int index = 0;
    subsetSumToK(nums, k, index, output);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}