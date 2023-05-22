#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(int a, int n)
{
    ll ans = 1;

    while (n > 0)
    {
        if (n & 1)
            ans = ans * a;

        n = n >> 1;
        a = a * a;
    }

    return ans;
}

ll mod_inv(ll a,ll n)
{
    return power(a,n-2);
}

ll boringFactorials(ll n, ll p)
{
    if (n >= p)
        return 0;

    ll ans = 1;

    for (ll i = n + 1; i < p; i++)
    {
        ans = ans * mod_inv(i, p);
        ans = ans % p;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        cout << boringFactorials(n, p) << endl;
    }

    return 0;
}