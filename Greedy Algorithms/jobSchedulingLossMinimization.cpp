#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] * b[1] == b[0] * a[1])
        return a[2] < b[2];
    else if (a[0] * b[1] < b[0] * a[1])
        return true;
    else
        return false;
}

vector<int> minLoss(vector<int> &time, vector<int> &loss)
{
    int n = time.size();
    vector<int> ans;

    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        a[i][0] = time[i];
        a[i][1] = loss[i];
        a[i][2] = i + 1;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i++)
        ans.push_back(a[i][2]);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> time(n), loss(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];
    for (int i = 0; i < n; i++)
        cin >> loss[i];

    vector<int> ans = minLoss(time, loss);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}