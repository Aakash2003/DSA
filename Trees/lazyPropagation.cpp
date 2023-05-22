#include <bits/stdc++.h>
#define M start + (end - start) / 2
using namespace std;

const int N = (int)(1e5 + 5);
int a[N];
int tree[4 * N], lazy[4 * N];

void pushDown(int start, int end, int pos)
{
    if (lazy[pos] > 0)
    {
        tree[pos] += (end - start + 1) * lazy[pos];
        if (start != end)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }

        lazy[pos] = 0;
    }
}

void build(int start, int end, int pos)
{
    if (start == end)
    {
        tree[pos] = a[start];
        return;
    }

    build(start, M, 2 * pos + 1);
    build(M + 1, end, 2 * pos + 2);
    tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

void update(int start, int end, int ul, int ur, int val, int pos)
{
    pushDown(start, end, pos);
    if (ul <= start && ur >= end)
    {
        lazy[pos] += val;
        pushDown(start, end, pos);
        return;
    }

    if (ur < start || ul > end)
        return;

    update(start, M, ul, ur, val, 2 * pos + 1);
    update(M + 1, end, ul, ur, val, 2 * pos + 2);
    tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

int query(int start, int end, int ql, int qr, int pos)
{
    pushDown(start, end, pos);

    if (ql <= start && qr >= end)
        return tree[pos];
    if (qr < start || ql > end)
        return 0;

    return query(start, M, ql, qr, 2 * pos + 1) + query(M + 1, end, ql, qr, 2 * pos + 2);
}
