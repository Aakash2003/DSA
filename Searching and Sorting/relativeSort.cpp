#include <bits/stdc++.h>
using namespace std;

vector<int> relative_sort(vector<int> &a, vector<int> &b)
{
    map<int, int> mp;
    int curr = 0;

    for (auto i : a)
        mp[i]++;

    for (auto i : b)
    {
        while (mp[i] > 0)
        {
            a[curr] = i;
            curr++, mp[i]--;
        }
    }

    for (auto i : mp)
    {
        while (i.second > 0)
        {
            a[curr] = i.first;
            curr++, i.second--;
        }
    }

    return a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> ans = relative_sort(a, b);
    for (auto i : ans)
        cout << i << " ";
}