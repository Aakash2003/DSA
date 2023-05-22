#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll a, ll d, ll n)
{
    ll ans = 1;

    while (d > 0)
    {
        if (d & 1)
        {
            ans = ((ans % n) * (a % n)) % n;
            d--;
        }

        d /= 2;
        a = (a * a) % n;
    }

    return ans;
}

bool check_composite(ll a, int s, ll d, ll n)
{
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    for (int i = 1; i < s; i++)
    {
        x = (x * x) % n;
        if (x == n - 1)
            return false;
    }

    return true;
}

bool millerRabin(ll n)
{
    if (n < 4)
        return n == 2 || n == 3;

    int primes[] = {2, 3, 5, 7};

    ll d = n - 1;
    int s = 0;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (int a : primes)
    {
        if (check_composite(a, s, d, n) == true)
            return false;
    }

    return true;
}

int main()
{
    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        if (millerRabin(n) == true)
            cout << n << " is a prime";
        else
            cout << n << " is not a prime";
    }
}