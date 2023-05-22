#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isCollinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    long long orientation = (x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1);

    if (orientation == 0)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        if (isCollinear(x1, y1, x2, y2, x3, y3))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}