#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    vector<int> g = {0, 1, 2, 2, 3, 3, 0, 0, 0, 0, 0, 0};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (a[i] >= 12)
                a[i] /= 12;
            ans ^= g[a[i]];

            if (ans == 0)
                cout << "Henry" << endl;
            else
                cout << "Derek" << endl;
        }
    }
}