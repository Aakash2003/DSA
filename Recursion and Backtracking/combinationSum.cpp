#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> ans;

void combination_sum(vector<int> &nums, int index, int target, vector<int> &output)
{
    int n = nums.size();
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }

    if (index >= n || target - nums[index] < 0)
        return;

    output.push_back(nums[index]);
    combination_sum(nums,index,target-nums[index],output);
    output.pop_back();

    combination_sum(nums,index+1,target,output);
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    vector<int> output;
    int index = 0;

    combination_sum(nums, index, target, output);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}