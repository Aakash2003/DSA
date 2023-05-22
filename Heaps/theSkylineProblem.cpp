#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second = b.second;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
    int n = buildings.size();
    vector<pair<int,int>> list;

    for(int i=0;i<n;i++)
    {
        int start = buildings[i][0],end = buildings[i][1],ht = buildings[i][2];
        list.push_back({start,-ht});
        list.push_back({end,ht});
    }

    sort(list.begin(),list.end(),cmp);
    priority_queue<int> pq;
    vector<vector<int>> ans;

    int curr_ht = 0;
    pq.push(0);

    for(int i=0;i<list.size();i++)
    {
        int x = list[i].first,ht = list[i].second;
        if(ht<0) pq.push(-ht);
        else pq.pop();
    }
}