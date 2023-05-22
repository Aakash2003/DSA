#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[21];

ll solve(int n)
{
    ll ans = (fact[n] / fact[n / 2]) / fact[n / 2];
    ans /= 2;
    ans = ans * fact[(n / 2) - 1] * fact[(n / 2) - 1];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    cout << solve(n) << endl;
}
