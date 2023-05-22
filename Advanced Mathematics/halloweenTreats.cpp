#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5;
ll pre[N + 1];
int rem[N + 1];

int main()
{
    int c, n, x;

    while (true)
    {
        cin >> c >> n;
        if (c == 0 && n == 0)
            break;

        rem[0] = 0;
        for (int i = 1; i < c; i++)
            rem[i] = -1;

        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            pre[i] = pre[i - 1] + x;
        }
        
        for (int i = 1; i <= n; i++)
        {
            int r = pre[i] % c;

            if(rem[r]!=-1) 
            {
                for(int L=rem[r]+1;L<=i;L++) cout<<L<<" ";
                cout<<endl;
                break;
            }
            else rem[r] = i;
        }
    }
}