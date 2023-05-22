#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 11;
int grundy[N];
multiset<int> vals;

int mex()
{
    int MEX = 0;
    while (vals.find(MEX) != vals.end())
        MEX++;

    return MEX;
}

int main()
{
    int n;
    cin>>n;
    int stones[n];
    for(int i=0;i<n;i++) cin>>stones[i];

    for(int i=0;i<=3;i++)
    {
        grundy[i] = i;
        vals.insert(i);
    }

    for(int i=4;i<N;i++)
    {
        vals.erase(vals.find(grundy[i-4]));
        grundy[i] = mex();
        vals.insert(grundy[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++) ans ^= grundy[stones[i]];

    if(ans>0) cout<<"Player 1"<<endl;
    else cout<<"Player 2"<<endl;
}