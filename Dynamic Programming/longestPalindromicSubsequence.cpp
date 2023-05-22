#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (j == i)
                dp[i][j] = 1;
            else if (j == i + 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            }
            else
            {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max({dp[i][j - 1], dp[i + 1][j]});
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindromeSubseq(s) << endl;
}