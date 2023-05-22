#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permuteUnique(vector<int> &nums, int index)
{
    int n = nums.size();
    if (index >= n)
    {
        ans.push_back(nums);
        return;
    }

    set<int> s;
    for (int i = index; i < n; i++)
    {
        if (s.count(nums[i]) != 0)
            continue;
        else
            s.insert(nums[i]);

        swap(nums[i], nums[index]);
        permuteUnique(nums, index + 1);
        swap(nums[i], nums[index]);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> output;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int index = 0;
    sort(nums.begin(), nums.end());

    permuteUnique(nums, index);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}