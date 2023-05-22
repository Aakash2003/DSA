#include <bits/stdc++.h>
using namespace std;

int distinctSubseqII(string s)
{
    int n = s.length();
    vector<long long int> dp(n + 1);
    dp[0] = 1;
    int mod = (int)(1e9 + 7);

    map<char, int> mp;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        char ch = s[i - 1];

        if (mp.count(ch) > 0)
        {
            int index = mp[ch];
            dp[i] = (dp[i] - dp[index - 1]) % mod;
        }

        mp[ch] = i;
    }

    if (dp[n] < 1)
        dp[n] += mod;

    return (int)dp[n] - 1;
}