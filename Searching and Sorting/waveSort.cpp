#include <bits/stdc++.h>
using namespace std;

void wave_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i += 2)
    {
        if (i > 0 && a[i] < a[i - 1])
            swap(a[i], a[i - 1]);
        if (i < n - 1 && a[i] < a[i + 1])
            swap(a[i], a[i + 1]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    wave_sort(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}