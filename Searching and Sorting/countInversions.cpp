#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(vector<int> &a, int start, int mid, int end)
{
    vector<int> left, right;
    
    for (int i = start; i <= mid; i++)
        left.push_back(a[i]);
    for (int i = mid + 1; i <= end; i++)
        right.push_back(a[i]);

    ll total = 0;
    int n = left.size(), m = right.size();
    int left_ptr = 0, right_ptr = 0;
    int curr = start;

    while (left_ptr < n && right_ptr < m)
    {
        if (left[left_ptr] <= right[right_ptr])
        {
            a[curr] = left[left_ptr];
            left_ptr++,curr++;
        }
        else
        {
            a[curr] = right[right_ptr];
            total += (n - left_ptr);
            right_ptr++,curr++;
        }
    }

    while (left_ptr < n)
    {
        a[curr] = left[left_ptr];
        left_ptr++,curr++;
    }

    while (right_ptr < m)
    {
        a[curr] = right[right_ptr];
        right_ptr++,curr++;
    }

    return total;
}

ll count_inversion(vector<int> &a, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    ll total = 0;

    total += count_inversion(a, start, mid);
    total += count_inversion(a, mid + 1, end);
    total += merge(a, start, mid, end);
    return total;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << count_inversion(a, 0, n - 1) << endl;
}