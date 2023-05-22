#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int left, int right)
{
    int pivot = left;
    int end = a[right];

    for (int i = left; i < right; i++)
    {
        if (a[i] <= end)
        {
            swap(a[pivot], a[i]);
            pivot++;
        }
    }

    swap(a[pivot],a[right]);
    return pivot;
}

void quick_sort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(a, left, right);
    quick_sort(a, left, pivot - 1);
    quick_sort(a, pivot + 1, right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}