#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string &s)
{
    int n = s.length();
    int maxi = 0;
    string ans = "";
    vector<vector<bool>> dp(n,vector<bool>(n));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(j==i) dp[i][j] = true;
            else if(j==i+1) 
            {
                if(s[i]==s[j]) dp[i][j] = true;
                else dp[i][j] = false;
            }
            else
            {
                if(s[i]==s[j] && dp[i+1][j-1]==true) dp[i][j] = true;
                else dp[i][j] = false;
            }

            if(dp[i][j]==true)
            {
                if(j-i+1>maxi) 
                {
                    maxi = j-i+1;
                    ans = s.substr(i,maxi);
                }
            }
        }
    }

    return ans;
}