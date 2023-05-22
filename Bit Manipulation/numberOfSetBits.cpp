#include <bits/stdc++.h>
using namespace std;

int numberOfSetBits(int n)
{
    int cnt = 0;
    while(n != 0)
    {
        int right_set_bit = n & (-n);
        n -= right_set_bit;
        cnt++;
    }

    return cnt;
}

int main()
{
    int n;
    cin>>n;
    cout<<numberOfSetBits(n)<<endl;
}