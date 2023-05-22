#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    int n = arr.size();
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(1e5, INT_MAX);
    dist[start] = 0;

    int mod = (int)1e5;

    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        int node = itr.first;
        int steps = itr.second;

        for (int i = 0; i < n; i++)
        {
            int num = (arr[i] * node) % mod;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int start,end;
    cin>>start>>end;

    cout<<minimumMultiplications(arr,start,end)<<endl;
}