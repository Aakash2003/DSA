#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    ll x1, y1, g;

    g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

ll apply_crt(ll nums[], ll rems[], ll N, int n)
{
    ll a = 0;

    for (int i = 0; i < n; i++)
    {
        ll temp = (rems[i] * (N / nums[i])) % N;
        ll x, y;
        ll g = extended_gcd(N / nums[i], nums[i], x, y);

        x = ((x % nums[i]) + nums[i]) % nums[i];

        temp = (temp * x) % N;
        a = (a + temp) % N;
    }

    return a;
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ll nums[n], rems[n];
        ll N = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            N *= nums[i];
        }

        for (int i = 0; i < n; i++)
            cin >> rems[i];

        ll a = apply_crt(nums, rems, N, n);

        for (int i = 0; i < n; i++)
        {
            cout << a << " % " << nums[i] << " = " << a % nums[i] << endl;
        }
    }
}