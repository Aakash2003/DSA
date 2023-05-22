#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = (int)(1e9 + 7);

void product(vector<vector<ll>> &a, vector<vector<ll>> &b, int n)
{

    ll temp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                temp[i][j] = (temp[i][j] + ((a[i][k] * b[k][j]) % mod)) % mod;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = temp[i][j];
    }
}

void power(vector<vector<ll>> &a, int m, int n)
{

    vector<vector<ll>> ans(m, vector<ll>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            if (i == j)
                ans[i][j] = 1;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            product(ans, a, m);
            n--;
        }

        n = n / 2;
        product(a, a, m);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int t, m, n;

    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        vector<vector<ll>> a(m, vector<ll>(m));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        power(a, m, n);
    }

    return 0;
}