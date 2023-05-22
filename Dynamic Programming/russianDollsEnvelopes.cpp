#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] > b[1];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            dp.push_back(envelopes[i][1]);
        else if (envelopes[i][1] > dp[dp.size() - 1])
            dp.push_back(envelopes[i][1]);
        else
        {
            int index = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            dp[index] = envelopes[i][1];
        }
    }

    return dp.size();
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> envelopes(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> envelopes[i][0] >> envelopes[i][1];

    cout << maxEnvelopes(envelopes) << endl;
}