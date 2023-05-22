#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (int)(2e5 + 5);
const int MAX = (int)(1e13 + 5);
int nums[N];
int tree[4 * N], lazy[4 * N];

void pushDown(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if (start != end)
        {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void build(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = nums[start];
        return;
    }

    int mid = start + (end - start) / 2;
    build(start, mid, 2 * node + 1);
    build(mid + 1, end, 2 * node + 2);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

void update(int start, int end, int l, int r, int v, int node)
{
    pushDown(start, end, node);
    if (l <= start && r >= end)
    {
        lazy[node] += v;
        pushDown(start, end, node);
        return;
    }
    else if (l > end || r < start)
        return;

    int mid = start + (end - start) / 2;
    update(start, mid, l, r, v, 2 * node + 1);
    update(mid + 1, end, l, r, v, 2 * node + 2);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int start, int end, int l, int r, int node)
{
    pushDown(start, end, node);
    if (l <= start && r >= end)
        return tree[node];
    else if (l > end || r < start)
        return MAX;

    int mid = start + (end - start) / 2;
    return min(query(start, mid, l, r, 2 * node + 1), query(mid + 1, end, l, r, 2 * node + 2));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    build(0, n - 1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, v;
        char ch;
        cin >> l >> r;
        ch = cin.get();
        if (ch == ' ')
        {
            cin >> v;
            if (l <= r)
                update(0, n - 1, l, r, v, 0);
            else
            {
                update(0, n - 1, l, n - 1, v, 0);
                update(0, n - 1, 0, r, v, 0);
            }
        }
        else
        {
            if (l <= r)
                cout << query(0, n - 1, l, r, 0) << endl;
            else
                cout << min(query(0, n - 1, l, n - 1, 0), query(0, n - 1, 0, r, 0)) << endl;
        }
    }
    
    return 0;
}