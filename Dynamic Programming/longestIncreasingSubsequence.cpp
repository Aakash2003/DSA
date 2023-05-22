#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e4);

class SegmentTree
{
    vector<int> tree;

    public:

    SegmentTree()
    {
        tree = vector<int>(2*N);
    }

    void update(int idx,int val)
    {
        idx += N;
        tree[idx] = val;
        while(idx>1)
        {
            tree[idx>>1] = max(tree[idx],tree[idx^1]);
            idx = idx>>1;
        }
    }

    int query(int l,int r)
    {
        int ans = 0;
        for(l+=N,r+=N;l<r;l = l>>1,r = r>>1)
        {
            if(l & 1) ans = max(ans,tree[l++]);
            if(r & 1) ans = max(ans,tree[--r]);
        }

        return ans;
    }
};

int lengthOfLIS1(vector<int> &nums)
{
    int n = nums.size();
    const int SCALE_UP = (int)(1e4+1);
    for(int i=0;i<n;i++) nums[i]+= SCALE_UP;

    SegmentTree st = SegmentTree();

    int dp[n];
    for(int i=0;i<n;i++) 
    {
        dp[i] = st.query(0,nums[i])+1;
        st.update(nums[i],dp[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans,dp[i]);
    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    int ans = 0, n = nums.size();
    vector<int> dp;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            dp.push_back(nums[i]);
        else if (nums[i] > dp[dp.size() - 1])
            dp.push_back(nums[i]);
        else
        {
            int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[index] = nums[i];
        }
    }

    return dp.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << lengthOfLIS(nums);
}