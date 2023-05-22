#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;

    int mask = 0x55555555;
    int ans = n & (n - 1);
    if (ans != 0)
        return false;

    if (n & mask)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    string ans[] = {"No", "Yes"};
    cout << ans[isPowerOfFour(n)] << endl;
}