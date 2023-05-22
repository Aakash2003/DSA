#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll fact(ll n)
{
    ll ans = 1;

    for (int i = 1; i <= n; i++)
        ans = (ans * i) % mod;

    return ans;
}

ll power(ll a, ll n)
{
    ll ans = 1;

    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % mod;

        n = n >> 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll mod_inv(ll n)
{
    return power(n, mod - 2);
}

ll C(ll n, ll r)
{
    if (r > n)
        return 0;

    ll ans = fact(n);
    ans = (ans * mod_inv(fact(r))) % mod;
    ans = (ans * mod_inv(fact(n - r))) % mod;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << C(n + m - 1, m);
}
