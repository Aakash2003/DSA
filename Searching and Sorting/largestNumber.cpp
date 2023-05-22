#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(string &a, string &b)
{
    string s1 = a + b;
    string s2 = b + a;
    return s1 > s2;
}

string largestNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<string> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(to_string(nums[i]));

    sort(arr.begin(), arr.end(), cmp);
    string ans = "";
    for (auto c : arr)
        ans += c;
    while (ans[0] == '0' && ans.length() > 1)
        ans.erase(0, 1);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
}