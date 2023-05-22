#include <bits/stdc++.h>
using namespace std;

string modify(string s)
{
    int n = s.length();
    string newString = "";
    for (int i = 0; i < n; i++)
    {
        newString += (char)('$');
        newString += (char)s[i];
    }

    newString += (char)('$');
    return newString;
}

vector<int> manchers(string s)
{
    int n = s.length();
    vector<int> nums(n);

    int c = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int mirror = 2 * c - i;
        if (i < r)
            nums[i] = min(nums[mirror], r - i);

        while (i + nums[i] + 1 < n && i - nums[i] - 1 >= 0 && s[i + nums[i] + 1] == s[i - nums[i] - 1])
            nums[i]++;

        if (i + nums[i] > r)
        {
            c = i;
            r = i + nums[i];
        }
    }

    return nums;
}

int main()
{
    string text;
    cin >> text;
    text = modify(text);
    vector<int> nums = manchers(text);
    int ans = *max_element(nums.begin(), nums.end());
    cout << ans << endl;
}