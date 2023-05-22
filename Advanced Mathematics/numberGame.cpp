#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isFastestFinger(ll n)
{
    if (n == 1)
        return true;
    if (n == 2)
        return false;
    if (n % 2 != 0)
        return false;
    if ((n & (n - 1)) == 0)
        return true;
    if (n % 4 == 0 && isPrime(n / 2))
        return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned ll n;
        cin >> n;
        string ans[] = {"Ashishgup", "FastestFinger"};
        cout << ans[isFastestFinger(n)] << endl;
    }
}