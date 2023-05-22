#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        double x[n], y[n];

        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        double area = 0;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            if (i == n - 1)
                j = 0;

            area += (y[i] + y[j]) * (x[j] - x[i]) / 2;
        }

        area = abs(area);
        long long ans = area;

        cout << ans << endl;
    }

    return 0;
}