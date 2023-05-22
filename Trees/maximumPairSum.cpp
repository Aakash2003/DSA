#include <bits/stdc++.h>
#define M start + (end - start) / 2
using namespace std;

const int N = (int)(1e5 + 5);
int a[N];
pair<int, int> tree[4 * N];

pair<int, int> combine(pair<int, int> l, pair<int, int> r)
{
    if (l.first < r.first)
        swap(l, r);

    return {l.first, max(l.second, r.first)};
}

void build(int start, int end, int pos)
{
    if (start == end)
    {
        tree[pos] = {a[start], -1};
        return;
    }

    build(start, M, 2 * pos + 1);
    build(M + 1, end, 2 * pos + 2);
    tree[pos] = combine(tree[2 * pos + 1], tree[2 * pos + 2]);
}

void update(int start, int end, int index, int val, int pos)
{
    if (start == end)
    {
        tree[pos] = {val, -1};
        return;
    }

    if (index <= M)
        update(start, M, index, val, 2 * pos + 1);
    else
        update(M + 1, end, index, val, 2 * pos + 2);
}

pair<int, int> query(int start, int end, int ql, int qr, int pos)
{
    if (ql <= start && qr >= end)
        return tree[pos];
    else if (qr < start || ql > end)
        return {-1, -1};

    return combine(query(start, M, ql, qr, 2 * pos + 1), query(M + 1, end, ql, qr, 2 * pos + 2));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, n - 1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        string type;
        cin >> type;
        if (type == "U")
        {
            int index, val;
            cin >> index >> val;
            index--;
            update(0, n - 1, index, val, 0);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            pair<int, int> ans = query(0, n - 1, l, r, 0);
            cout << (ans.first + ans.second) << endl;
        }
    }
}