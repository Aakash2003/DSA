#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int maxi = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c1 = s1[i - 1], c2 = s2[j - 1];
            if (c1 != c2)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + dp[i - 1][j - 1];

            maxi = max(maxi, dp[i][j]);
        }
    }

    return maxi;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstr(s1, s2) << endl;
}