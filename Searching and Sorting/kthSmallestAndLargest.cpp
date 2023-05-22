#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int left, int right)
{
    int pivot = left;
    int end = a[right];

    for(int i=left;i<right;i++)
    {
        if(a[i]<=end)
        {
            swap(a[i],a[pivot]);
            pivot++;
        }
    }

    swap(a[right],a[pivot]);
    return pivot;
}

int quick_select(vector<int> &a, int start, int end, int k)
{
    if (start >= end)
        return a[start];

    int pivot = partition(a, start, end);

    if (pivot + 1 == k)
        return a[pivot];
    else if (pivot + 1 > k)
        return quick_select(a, start, pivot - 1, k);
    else
        return quick_select(a, pivot + 1, end, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << quick_select(a, 0, n - 1, k) << " " << quick_select(a, 0, n - 1, n - k + 1);
    cout << endl;
}