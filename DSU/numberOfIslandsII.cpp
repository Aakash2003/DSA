#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class DSU
{
    vector<int> parent;
    vector<int> subtree_size;
    int N;

public:
    DSU(int n)
    {
        N = n;
        parent = vector<int>(n, 0);
        subtree_size = vector<int>(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findRoot(int u)
    {
        while (u != parent[u])
        {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }

    void combine(int u, int v)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);

        if (ru == rv)
            return;

        if (subtree_size[ru] > subtree_size[rv])
        {
            parent[rv] = ru;
            subtree_size[ru] += subtree_size[rv];
        }
        else
        {
            parent[ru] = rv;
            subtree_size[rv] += subtree_size[ru];
        }
    }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries)
{
    vector<int> ans;
    DSU dsu = DSU(n * m);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;

    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];

        if (visited[x][y] == true)
        {
            ans.push_back(cnt);
            continue;
        }

        visited[x][y] = true;
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == true)
            {
                int nodeNumber = x * m + y;
                int adjNodeNumber = newX * m + newY;
                if (dsu.findRoot(nodeNumber) != dsu.findRoot(adjNodeNumber))
                {
                    cnt--;
                    dsu.combine(nodeNumber, adjNodeNumber);
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int q;
        cin >> q;

        vector<vector<int>> queries(q, vector<int>(2));
        for (int i = 0; i < q; i++)
            cin >> queries[i][0] >> queries[i][1];

        vector<int> ans = numOfIslands(n, m, queries);
        for (auto i : ans)
            cout << i << " ";
    }

    return 0;
}
