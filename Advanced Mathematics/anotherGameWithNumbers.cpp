#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll d[15];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll get_lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

ll powerOfTwo(ll x)
{
    return (1ll << x);
}

ll solve(ll n, ll k)
{
    ll ans = 0;
    for (int mask = 1; mask < powerOfTwo(k); mask++)
    {
        ll lcm = 1ll;
        int cnt = 0;
        bool flag = true;

        for (int i = 0; i < k; i++)
        {
            if (mask & powerOfTwo(i))
            {
                cnt++;
                lcm = get_lcm(lcm, d[i]);
                if (lcm > n)
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag == false)
            continue;

        if (cnt & 1)
            ans += n / lcm;
        else
            ans -= n / lcm;
    }

    return (n - ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> d[i];

    cout << solve(n, k) << endl;
    return 0;
}