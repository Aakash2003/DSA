#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000000 + 7;

void product(ll a[2][2], ll b[2][2], int n)
{
    ll temp[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = temp[i][j];
    }
}

ll fib_sum(ll n)
{
    if (n == 0)
        return 0;

    ll T[2][2] = {{1, 1}, {1, 0}};
    ll ans[2][2] = {{1, 0}, {0, 1}};

    while (n > 0)
    {
        if (n & 1)
        {
            product(ans, T, 2);
            n--;
        }

        n /= 2;
        product(T, T, 2);
    }

    ll sum = (ans[0][0] + ans[0][1] - 1) % mod;

    if (sum < 0)
        sum += mod;

    return sum;
}

int main()
{
    ll t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        ll ans = (fib_sum(m) - fib_sum(n - 1)) % mod;
        if (ans < 0)
            ans += mod;
        cout << ans << endl;
    }
}
