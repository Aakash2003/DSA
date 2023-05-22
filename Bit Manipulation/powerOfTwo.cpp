#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    int ans = n & (n - 1);
    if (ans == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin>>n;
    string ans[] = {"No","Yes"};
    cout<<ans[isPowerOfTwo(n)]<<endl;
}
