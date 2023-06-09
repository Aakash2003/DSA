#include <bits/stdc++.h>
using namespace std;

const int BLK_SZ = 1000;

typedef struct query
{
    int l, r, t, index;

    query()
    {
        l = r = t = index = 0;
    }
} query;

int get_block(int i)
{
    return (i / BLK_SZ);
}

bool cmp(query &a, query &b)
{
    if (get_block(a.l) != get_block(b.l))
        return a.l < b.l;
    else if (get_block(a.r) != get_block(b.r))
        return a.r < b.r;
    return a.t < b.t;
}

int ans = 0;
unordered_map<int, int> freq;

void add(int x)
{
    if (freq[x] == 0)
    {
        ans++;
        freq[x]++;
    }
    else
    {
        freq[x]++;
    }
}

void remove(int x)
{
    if (freq[x] == 1)
    {
        ans--;
        freq[x]--;
    }
    else
    {
        freq[x]--;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;
    vector<query> queries;
    vector<pair<int, pair<int, int>>> updates;
    int num_updates = 0;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            query curr_query;
            curr_query.l = l;
            curr_query.r = r;
            curr_query.t = num_updates;
            curr_query.index = queries.size();
            queries.push_back(curr_query);
        }
        else
        {
            int idx, x;
            cin >> idx >> x;
            idx--;
            updates.push_back({idx, {x, -1}});
            num_updates++;
        }
    }

    sort(queries.begin(), queries.end(), cmp);
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = arr[i];

    for (int i = 0; i < updates.size(); i++)
    {
        int index = updates[i].first;
        int val = updates[i].second.first;
        updates[i].second.second = b[index];
        b[index] = val;
    }

    int L = queries[0].l;
    int R = L - 1;

    int timestamp = -1;

    int num_queries = queries.size();
    int query_ans[num_queries];

    for (int i = 0; i < num_queries; i++)
    {
        int index = queries[i].index;
        int l = queries[i].l;
        int r = queries[i].r;
        int t = queries[i].t;

        while (R < r)
        {
            R++;
            add(arr[R]);
        }
        while (R > r)
        {
            remove(arr[R]);
            R--;
        }
        while (L < l)
        {
            remove(arr[L]);
            L++;
        }
        while (L > l)
        {
            L--;
            add(arr[L]);
        }
        while (timestamp < t)
        {
            timestamp++;
            int up_index = updates[timestamp].first;
            int new_val = updates[timestamp].second.first;
            int old_val = updates[timestamp].second.second;
            if (up_index >= L and up_index <= R)
                remove(old_val);
            arr[up_index] = new_val;
            if (up_index >= L and up_index <= R)
                add(new_val);
        }
        while (timestamp > t)
        {
            int up_index = updates[timestamp].first;
            int new_val = updates[timestamp].second.second;
            int old_val = updates[timestamp].second.first;
            if (up_index >= L and up_index <= R)
                remove(old_val);
            arr[up_index] = new_val;
            if (up_index >= L and up_index <= R)
                add(new_val);
        }
        query_ans[index] = ans;
    }

    for (int i = 0; i < num_queries; i++)
        cout << query_ans[i] << "\n";

    return 0;
}
