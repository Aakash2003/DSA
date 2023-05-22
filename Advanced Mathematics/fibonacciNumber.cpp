#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = (int)(1e9+7);

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

int fib(int n)
{
    if (n <= 2)
        return 1;
        
    ll T[2][2] = {{1, 1}, {1, 0}};
    ll ans[2][2] = {{1, 0}, {0, 1}};
    int p = n - 2;

    while (p > 2)
    {
        if (p & 1)
        {
            product(ans, T, 2);
            p--;
        }

        p /= 2;
        product(T, T, 2);
    }

    int result = (ans[0][0] + ans[0][1]) % mod;
    return result;
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << fib(n) << endl;
    }
}