#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    if (n == 1)
        return 1;

    int ans = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans *= (i - 1);
            ans /= i;

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
    {
        ans *= (n - 1);
        ans /= n;
    }

    return ans;
}

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<phi(n)<<endl;
    }

    return 0;
}