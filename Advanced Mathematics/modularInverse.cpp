#include <bits/stdc++.h>
using namespace std;

int extended_GCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    int x1, y1;

    int g = extended_GCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main()
{

    int t, a, m;
    cin >> t;

    while (t--)
    {
        cin >> a >> m;
        int x, y;

        int g = extended_GCD(a, m, x, y);

        if (g == 1)
        {
            x = ((x % m) + m) % m;
            cout << "Modulo Inverse of " << a << " is " << x << " for m = " << m << endl;
        }
        else
            cout << "Modulo Inverse does not exits" << endl;
    }
}