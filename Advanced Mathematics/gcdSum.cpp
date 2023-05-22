#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000000;
int phi[N + 1];

void preprocess()
{
    for (int i = 1; i <= N; i++)
        phi[i] = i;
}

ll gcd_sum(int n)
{
    ll ans = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll d1 = i;
            ll d2 = n / i;

            ans += d1 * phi[n / d1];

            if (d1 != d2)
                ans += d2 * phi[n / d2];
        }
    }

    return ans;
}

int main()
{
    int t, n;
    cin >> t;

    preprocess();

    while (t--)
    {
        cin >> n;
        cout << gcd_sum(n) << endl;
    }
}