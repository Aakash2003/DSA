#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll M = 1e9 + 7;

ll mod(ll n)
{
    return (n % M + M) % M;
}

ll add(ll a, ll b)
{
    return mod(mod(a) + mod(b));
}

ll sub(ll a, ll b)
{
    return mod(mod(a) - mod(b) + M);
}

ll mul(ll a, ll b)
{
    return mod(mod(a) * mod(b));
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    int tn = text.length(), pn = pattern.length();
    ll p = 31;

    vector<ll> powMod(tn);
    powMod[0] = 1;

    for (int i = 1; i < tn; i++)
        powMod[i] = mul(powMod[i - 1], p);

    ll pattern_hash = 0;
    for (int i = 0; i < pn; i++)
        pattern_hash = add(pattern_hash, mul(pattern[i] - 'a' + 1, powMod[i]));

    vector<ll> text_hash(tn + 1);
    for (int i = 0; i < tn; i++)
        text_hash[i + 1] = add(text_hash[i], mul(text[i] - 'a' + 1, powMod[i]));

    for (int i = 0; i < tn - pn + 1; i++)
    {
        ll hash_val = sub(text_hash[i + pn], text_hash[i]);
        if (hash_val == mul(pattern_hash, powMod[i]))
            cout << "Pattern found at index " << i << endl;
    }

    return 0;
}