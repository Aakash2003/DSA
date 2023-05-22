#include<bits/stdc++.h>
using namespace std;

bool PredictTheWinner(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(n));

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0) dp[i][j] = 0;
            else if(gap==1) dp[i][j] = max(nums[i],nums[j]);
            else
            {
                int val1 = nums[i] + min(dp[i+2][j],dp[i+1][j-1]);
                int val2 = nums[j] + min(dp[i+1][j-1],dp[i][j-2]);
                dp[i][j] = max(val1,val2);
            }
        }
    }

    return dp[0][n-1];
}
