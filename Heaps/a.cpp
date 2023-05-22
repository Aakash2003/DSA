#include <bits/stdc++.h>
using namespace std;

auto cmp = [](int a, int b)
{
    return a>b;
};

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);

    for(int i=0;i<n;i++) pq.push(a[i]);
    
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}