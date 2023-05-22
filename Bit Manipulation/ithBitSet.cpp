#include <bits/stdc++.h>
using namespace std;

bool ithBitSet(int n, int i)
{
    int d = 1;
    d = d << i;
    int ans = n & d;
    
    if (ans == 0)
        return false;
    else
        return true;
}

int main()
{
    int n,i;
    cin>>n>>i;
    string ans[] = {"No","Yes"};
    cout<<ans[ithBitSet(n,i)]<<endl;
}