#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void subsets(vector<int> &nums, vector<int> &output, int index)
{
    int n = nums.size();
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    output.push_back(nums[index]);
    subsets(nums, output, index + 1);
    output.pop_back();

    subsets(nums, output, index + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> output;
    int index = 0;

    subsets(nums, output, index);
    sort(ans.begin(), ans.end());

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
