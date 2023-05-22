#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &barn, int k, int mid)
{
    int n = barn.size();
    int total = 1, last = 0;

    for (int i = 1; i < n; i++)
    {
        if (barn[i] - barn[last] >= mid)
        {
            total++;
            last = i;
        }
    }

    return (total >= k);
}

int solve(vector<int> stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> barn(n);
        for (int i = 0; i < n; i++)
            cin >> barn[i];

        sort(barn.begin(), barn.end());

        int start = 1, end = 1e9 + 5;
        int ans = 1e9 + 5;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (check(barn, k, mid) == true)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        cout << ans << endl;
    }
}