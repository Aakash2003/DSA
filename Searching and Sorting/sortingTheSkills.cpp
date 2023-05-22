#include <bits/stdc++.h>
using namespace std;

bool check_sort(vector<int> &a)
{
    int n = a.size();
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            if(a[i+1]==a[i]-1) swap(a[i],a[i+1]);
            else return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        if(check_sort(a)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
}