#include <bits/stdc++.h>
using namespace std;

int minCut(string s)
{
    int n = s.length();
    vector<vector<bool>> storage(n, vector<bool>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                storage[i][j] = true;
            else if (j == i+1)
            {
                if (s[i] == s[j])
                    storage[i][j] = true;
                else
                    storage[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] && storage[i + 1][j - 1] == true)
                    storage[i][j] = true;
                else
                    storage[i][j] = false;
            }
        }
    }

    vector<int> dp(n);
    dp[0] = 0;

    for (int j = 1; j < n; j++)
    {
        if (storage[0][j] == true)
            dp[j] = 0;
        else
        {
            int mini = INT_MAX;
            for (int i = j; i >= 1; i--)
            {
                if (storage[i][j] == true)
                    mini = min(mini, dp[i - 1]);
            }

            dp[j] = mini + 1;
        }
    }

    return dp[n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << minCut(s) << endl;
}