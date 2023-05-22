#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> seg(n);
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            cin >> seg[i].first >> seg[i].second;
            left[i] = seg[i].first;
            right[i] = seg[i].second;
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int ans = n - 1;

        for (int i = 0; i < n; i++)
        {
            int left_ptr = lower_bound(right.begin(), right.end(), seg[i].first) - right.begin();
            int right_ptr = lower_bound(left.begin(), left.end(), seg[i].second + 1) - left.begin();
            ans = min(ans, n - right_ptr + left_ptr);
        }

        cout << ans << endl;
    }
}