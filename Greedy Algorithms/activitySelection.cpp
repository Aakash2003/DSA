#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end)
{
    int n = start.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        a.push_back({start[i], end[i]});

    sort(a.begin(), a.end(), cmp);

    int cnt = 1;
    int last = a[0].second;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first > last)
        {
            cnt++;
            last = a[i].second;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];

    cout << activitySelection(start, end) << endl;
}