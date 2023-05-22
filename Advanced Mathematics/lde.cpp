#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main()
{
    int a, b, c, g, x, y;
    cin >> a >> b >> c;
    g = extended_gcd(a, b, x, y);

    x = (x * c) / g, y = (y * c) / g;

    if (c % g == 0)
        cout << "x = " << x << " y = " << y;
    else
        cout << "solution to this linear diophantine equation does not exist";
}