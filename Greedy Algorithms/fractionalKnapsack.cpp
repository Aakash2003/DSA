#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int val;
    int wt;
};

bool cmp(Item &a, Item &b)
{
    double r1 = (double)1.0 * a.val / a.wt;
    double r2 = (double)1.0 * b.val / b.wt;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item> &arr, int W)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), cmp);

    int curr_wt = 0;
    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr_wt + arr[i].wt <= W)
        {
            curr_wt += arr[i].wt;
            ans += arr[i].val;
        }
        else
        {
            int remaining = W - curr_wt;
            ans += (double)(remaining) * (1.0 * arr[i].val) / arr[i].wt;
            break;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<Item> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].val >> arr[i].wt;

    int w;
    cin >> w;
    cout << fractionalKnapsack(arr, w) << endl;
}