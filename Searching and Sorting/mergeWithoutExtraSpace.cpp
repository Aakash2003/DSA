#include<bits/stdc++.h>
#define ll long long
using namespace std;

void merge(vector<ll> &arr1,vector<ll> &arr2)
{
    int n = arr1.size(),m = arr2.size();
    int gap = (int)ceil((n+m)/2);
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> arr1(n),arr2(m);
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    merge(arr1,arr2);
}