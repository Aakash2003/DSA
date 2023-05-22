#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll findSubarray(vector<ll> &arr)
{
    int n = arr.size();
    ll cnt = 0, sum = 0;
    map<ll, ll> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.count(sum) == 0)
            mp[sum] = 1;
        else
        {
            cnt += mp[sum];
            mp[sum]++;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findSubarray(arr) << endl;
}