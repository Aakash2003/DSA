#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int mini = INT_MAX;
    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
        mini = min(mini, abs(arr[i + 1] - arr[i]));

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(arr[i + 1] - arr[i]) == mini)
            ans.push_back({arr[i], arr[i + 1]});
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans = minimumAbsDifference(arr);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}