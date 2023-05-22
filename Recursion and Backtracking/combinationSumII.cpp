#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> ans;

void combination_sumII(vector<int> &nums, int index, int target, vector<int> &output)
{
    int n = nums.size();
    if(target==0)
    {
        ans.push_back(output);
        return;
    }

    if(index>=n || target-nums[index] < 0) return;

    
}

int main()
{
    int n,target;
    cin>>n>>target;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    sort(nums.begin(),nums.end());
    vector<int> output;
    int index = 0;

    combination_sumII(nums,index,target,output);

}