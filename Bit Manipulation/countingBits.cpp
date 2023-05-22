#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll powerOfTwo(int x)
{
    return (1 << x);
}

ll countSetBits(ll n)
{
    if (n == 0)
        return 0;

    ll ans = 0, x = (int)floor(log2(n));
    ans += (powerOfTwo(x - 1) * x) + (n - powerOfTwo(x) + 1) + countSetBits(n - powerOfTwo(x));
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    cout << countSetBits(n) << endl;
}