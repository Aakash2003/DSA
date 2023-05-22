#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    int n = nums.size(), count = 0;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) a.push_back({nums[i],i});
    sort(a.begin(),a.end());
    int cnt = 0;

    for(int i=0;i<n;i++)
    {
        if(a[i].second)
        if(a[i].second!=i)
        {
            cnt++;
            swap(a[i],a[a[i].second]);
            i--;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << minSwaps(nums) << endl;
}