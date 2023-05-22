#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++) nums.push_back({arr[i],i});

    sort(nums.begin(),nums.end());
    int ans = 0;

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true||nums[i].second==i) continue;

        int cycle_len = 0;
        int j = i;

        while(!visited[j])
        {
            visited[j] = true;
            cycle_len++;
            j = nums[j].second;
        }

        ans += (cycle_len - 1);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<minSwaps(arr);
}