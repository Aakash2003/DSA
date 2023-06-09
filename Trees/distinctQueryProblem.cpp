#include <bits/stdc++.h>
using namespace std;

typedef struct query
{
    int l, r, blk_no, i;
    query()
    {
        l = r = blk_no = i = -1;
    }

    query(int L, int R, int B, int idx)
    {
        l = L;
        r = R;
        blk_no = L / B;
        i = idx;
    }
} query;

const int N = (int)(1e5 + 5);
int a[N];
int B;

const int M = (int)(1e6 + 5);
int freq[M];

int ans = 0;

void add(int i)
{
    freq[a[i]] += 1;
    if (freq[a[i]] == 1)
        ans++;
}

void remove(int i)
{
    freq[a[i]] -= 1;
    if (freq[a[i]] == 0)
        ans--;
}

bool cmp(query &a, query &b)
{
    if (a.blk_no != b.blk_no)
        return a.blk_no < b.blk_no;
    return a.r < b.r;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    B = sqrt(n);

    int q;
    cin >> q;
    query queries[q];
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[i] = query(l, r, B, i);
    }

    sort(queries, queries + q, cmp);
    int ans_to_queries[q];

    int L = queries[0].l;
    int R = queries[0].l - 1;

    for (int i = 0; i < q; i++)
    {
        while (R < queries[i].r)
        {
            R++;
            add(R);
        }

        while (R > queries[i].r)
        {
            remove(R);
            R--;
        }

        while (L < queries[i].l)
        {
            remove(L);
            L++;
        }

        while (L > queries[i].l)
        {
            L--;
            add(L);
        }

        ans_to_queries[queries[i].i] = ans;
    }

    for (int i = 0; i < q; i++)
        cout << ans_to_queries[i] << endl;

    return 0;
}