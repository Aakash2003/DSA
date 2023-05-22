#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> tree[n + 1];
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v), tree[v].push_back(u);
            degree[u]++, degree[v]++;
        }

        vector<int> timeRemoval(n + 1, 0);

        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (degree[i] == 1)
            {
                timeRemoval[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : tree[u])
            {
                degree[v]--;
                if (degree[v] <= 1 and timeRemoval[v] == 0)
                {
                    timeRemoval[v] = timeRemoval[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (timeRemoval[i] > k)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}