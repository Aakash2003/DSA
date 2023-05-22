#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 15;
int dp[51][1<<M];

int powerOfTwo(int x)
{
    return (1 << x);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int nums[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> nums[i];

        vector<int> primes;
        for (int i = 2; i < 51; i++)
        {
            bool isDivisible = false;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isDivisible = true;
                    break;
                }
            }

            if (!isDivisible)
                primes.push_back(i);
        }

        int pf_mask[n + 1];
        for (int i = 1; i <= n; i++)
        {
            int mask = 0;
            for (int j = 0; j < primes.size(); j++)
            {
                if (nums[i] % primes[j] == 0)
                    mask |= powerOfTwo(j);
            }

            pf_mask[i] = mask;
        }

        int m = primes.size();
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < powerOfTwo(m); j++)
                dp[i][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int mask = 0; mask < powerOfTwo(m); mask++)
            {
                if (pf_mask[i] & mask)
                    dp[i][mask] = dp[i - 1][mask];
                else
                    dp[i][mask] = max(1 + dp[i - 1][mask | pf_mask[i]], dp[i - 1][mask]);
            }
        }

        cout<<dp[n][0]<<endl;
    }
}
