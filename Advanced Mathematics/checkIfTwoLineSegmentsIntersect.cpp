#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Point
{
    ll x;
    ll y;
};

bool onSegment(Point a, Point b, Point c)
{
    if (b.x >= min(a.x, c.x) && b.x <= max(a.x, c.x) && b.y >= min(a.y, c.y) && b.y <= max(a.y, c.y))
        return true;

    return false;
}

int orientation(Point a, Point b, Point c)
{
    ll o = (c.x - b.x) * (b.y - a.y) - (c.y - b.y) * (b.x - a.x);
    if (o == 0)
        return 0;
    else if (o > 0)
        return 1;
    else
        return -1;
}

bool intersect(Point a1, Point a2, Point b1, Point b2)
{
    int o1 = orientation(a1, a2, b1);
    int o2 = orientation(a1, a2, b2);
    int o3 = orientation(b1, b2, a1);
    int o4 = orientation(b1, b2, a2);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(a1, b1, a2))
        return true;
    if (o2 == 0 && onSegment(a1, b2, a2))
        return true;
    if (o3 == 0 && onSegment(b1, a1, b2))
        return true;
    if (o4 == 0 && onSegment(b1, a2, b2))
        return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        struct Point a1, a2, b1, b2;
        a1 = {x1, y1}, a2 = {x2, y2}, b1 = {x3, y3}, b2 = {x4, y4};
        string ans[] = {"NO", "YES"};
        cout << ans[intersect(a1, a2, b1, b2)] << endl;
    }
}