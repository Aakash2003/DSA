#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    stack<vector<int>> s1;

    for(int i=0;i<n;i++)
    {
        if(i==0) s1.push({intervals[i][0],intervals[i][1]});
        else
        {
            int end = s1.top()[1];
            if(intervals[i][0]>end) s1.push({intervals[i][0],intervals[i][1]});
            else s1.top()[1] = max(end,intervals[i][1]);
        }
    }

    while(!s1.empty())
    {
        ans.push_back(s1.top());
        s1.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}