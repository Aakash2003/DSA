#include <bits/stdc++.h>
using namespace std;

const int N = (int)(2e5 + 5);
vector<int> tree[N];
vector<int> dfs_order;
int first_index[N], last_index[N];

void dfs(int s)
{
    dfs_order.push_back(s);
    first_index[s] = dfs_order.size() - 1;

    for (int v : tree[s])
        dfs(v);

    last_index[s] = dfs_order.size() - 1;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int pi;
        cin >> pi;
        tree[pi].push_back(i);
    }

    dfs(1);

    while (q--)
    {
        int ui, ki;
        cin >> ui >> ki;
        int index = first_index[ui];
        index += ki - 1;
        if (index > last_index[ui])
            cout << "-1" << endl;
        else
            cout << dfs_order[index] << "\n";
    }

    return 0;
}