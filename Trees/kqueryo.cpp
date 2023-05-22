#include <bits/stdc++.h>
using namespace std;

const int N = (int)(3e5 + 5);
int nums[N];
vector<int> tree[4 * N];

void build(int start, int end, int node)
{
    if (start == end)
    {
        tree[node].push_back(nums[start]);
        return;
    }

    int mid = start + (end - start) / 2;
    build(start, mid, 2 * node + 1);
    build(mid + 1, end, 2 * node + 2);
    merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(), tree[2 * node + 2].end(), back_inserter(tree[node]));
}

int query(int start, int end, int ql, int qr, int k, int node)
{
    if (ql <= start && qr >= end)
    {
        auto itr = upper_bound(tree[node].begin(), tree[node].end(), k);
        int numLess = itr - tree[node].begin();
        return (end - start + 1 - numLess);
    }
    else if (ql > end || qr < start)
        return 0;

    int mid = start + (end - start) / 2;
    return query(start, mid, ql, qr, k, 2 * node + 1) + query(mid + 1, end, ql, qr, k, 2 * node + 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    build(0, n - 1, 0);

    int q;
    cin >> q;
    int ans = 0;

    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a ^= ans, b ^= ans, c ^= ans;

        if (a < 1)
            a = 1;
        if (b > n)
            b = n;
        if (a > b)
        {
            ans = 0;
            cout << ans << endl;
            continue;
        }

        a--, b--;
        ans = query(0, n - 1, a, b, c, 0);
        cout << ans << endl;
    }
}