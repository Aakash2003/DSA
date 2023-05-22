#include<bits/stdc++.h>
using namespace std;

int leftShift(int a,int x)
{
    return (a<<x);
}

int copySetBits(int x,int y,int l,int r)
{
    int mask = leftShift(1,r-l+1);
    mask--;
    mask = leftShift(mask,l-1);
    mask = mask & x;
    y = y | mask;
    return y;
}

int main()
{
    int x,y,l,r;
    cin>>x>>y>>x>>r;
}