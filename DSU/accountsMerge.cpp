#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    DSU dsu = DSU(n);
    map<string, int> mailToNode;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mailToNode.count(mail) == 0)
                mailToNode[mail] = i;
            else
                dsu.combine(i, mailToNode[mail]);
        }
    }

    vector<string> mergedMail[n];
    for (auto i : mailToNode)
    {
        string mail = i.first;
        int node = dsu.findRoot(i.second);
        mergedMail[node].push_back(mail);
    }

    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].size() == 0)
            continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> output;
        output.push_back(accounts[i][0]);
        for (auto j : mergedMail[i])
            output.push_back(j);

        ans.push_back(output);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> accounts(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < accounts[i].size(); j++)
            cin >> accounts[i][j];
    }

    vector<vector<string>> ans = accountsMerge(accounts);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}