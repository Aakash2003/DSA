#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll> &tree, ll mid, ll m)
{
    int n = tree.size();
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] - mid > 0)
            total += (tree[i] - mid);
    }

    return total >= m;
}

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> tree(n);
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    sort(tree.begin(), tree.end());

    ll start = 1, end = *max_element(tree.begin(), tree.end());
    ll ans = 0;

    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (check(tree, mid, m))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << ans << endl;

    return 0;
}
