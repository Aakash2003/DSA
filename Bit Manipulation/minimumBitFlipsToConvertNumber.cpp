#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start,int goal)
{
    int flip = start^goal;
    int cnt = 0;

    while(flip!=0)
    {
        int right_set_bit = flip & (-flip);
        flip -= right_set_bit;
        cnt++;
    }

    return cnt;
}

int main()
{
    int start,goal;
    cin>>start>>goal;
    cout<<minBitFlips(start,goal)<<endl;
}