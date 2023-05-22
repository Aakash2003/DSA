#include <bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n)
{
    int odd_mask = 0x55555555, even_mask = 0xAAAAAAAA;
    int odd = n & odd_mask, even = n & even_mask;
    odd = odd << 1, even = even >> 1;
    return odd | even;
}

int main()
{
    unsigned int n;
    cin>>n;
    cout<<swapBits(n)<<endl;
}