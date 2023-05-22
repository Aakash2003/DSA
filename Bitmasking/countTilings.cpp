#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = (int)(1e9 + 7);
vector<int> next_mask;

int powerOfTwo(int x)
{
    return (1<<x);
}

void gen_next_mask(int mask, int i, int n, int curr_mask)
{
    if (i == n)
    {
        next_mask.push_back(curr_mask);
        return;
    }

    if (mask & (1 << i))
        gen_next_mask(mask, i + 1, n, curr_mask);
    else
    {
        gen_next_mask(mask, i + 1, n, curr_mask | powerOfTwo(i));
        if ((i + 1) < n and (mask & powerOfTwo(i+1)) == 0)
            gen_next_mask(mask, i + 2, n, curr_mask);
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> all_next_masks[powerOfTwo(n)];

    for (int mask = 0; mask < powerOfTwo(n); mask++)
    {
        next_mask.clear();
        gen_next_mask(mask, 0, n, 0);
        all_next_masks[mask] = next_mask;
    }

    int dp[m + 1][powerOfTwo(n)];

    for (int i = 0; i < powerOfTwo(n); i++)
        dp[0][i] = 0;
    

    dp[0][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int mask = 0; mask < powerOfTwo(n); mask++)
        {
            dp[i][mask] = 0;
            for (int j : all_next_masks[mask])
                dp[i][mask] = (dp[i][mask] + dp[i - 1][j]) % MOD;    
        }
    }

    cout << dp[m][0];
    return 0;
}