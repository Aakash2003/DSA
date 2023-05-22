#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e5 + 5);
int bit[N];

int query(int r, int n)
{
    int ans = 0;
    int i = r + 1;

    while (i > 0)
    {
        ans += bit[i];
        int right_set_bit = (i & (-i));
        i -= right_set_bit;
    }

    return ans;
}

void update(int k, int delta, int n)
{
    k++;
    while (k <= n)
    {
        bit[k] += delta;
        int right_set_bit = (k & (-k));
        k -= right_set_bit;
    }
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
        update(i, nums[i], n);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            int index, val;
            cin >> index >> val;
            int delta = val - nums[index];
            nums[index] = val;
            update(index, delta, n);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            int ans = query(r, n);
            if (l > 0)
                ans -= query(l - 1, n);

            cout << ans << endl;
        }
    }
    return 0;
}