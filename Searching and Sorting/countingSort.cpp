#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mini = *min_element(a.begin(), a.end());
    int maxi = *max_element(a.begin(), a.end());

    vector<int> freq(maxi - mini + 1);

    for (int i = 0; i < n; i++)
        freq[a[i] - mini]++;

    int m = freq.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < freq[i]; j++)
            cout << i + mini << " ";
    }
}