#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price)
{
    int n = price.size();
    price.resize(n + 1);

    for (int i = n; i >= 1; i--)
        price[i] = price[i - 1];

    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = price[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = price[i];
        int left = 1, right = i - 1;

        while (left <= right)
        {
            dp[i] = max({dp[i],dp[left]+dp[right]});
            left++, right--;
        }
    }

    return dp[n];
}

int main()
{
}