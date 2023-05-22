#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(int a, int n, int p)
{
    ll ans = 1;
    a %= p;

    while (n > 0)
    {
        if (n & 1)
        {
            ans = ((ans % p) * (a % p)) % p;
            n--;
        }

        a *= a;
        n /= 2;
    }

    return ans;
}

int main()
{
    int t, a, n, p;
    cin >> t;

    while (t--)
    {
        cin >> a >> n >> p;
        cout << power(a, n, p) << endl;
    }

    return 0;
}