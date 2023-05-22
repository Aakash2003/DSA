#include <bits/stdc++.h>
using namespace std;

int leftShift(int a, int b)
{
    return a << b;
}

int powerOfTwo(int x)
{
    return 1 << x;
}

int divide(int dividend, int divisor)
{
    if (dividend == 0 && divisor != 0)
        return 0;
    if (dividend == divisor)
        return 1;

    bool isPositive = false;
    if (dividend > 0 && divisor > 0)
        isPositive = true;
    if (dividend < 0 && divisor < 0)
        isPositive = true;

    unsigned int a = abs(dividend), b = abs(divisor);
    unsigned int ans = 0;

    while (a >= b)
    {
        int q = 0;
        int x = leftShift(b, q + 1);

        while (a > x)
        {
            q++;
            x = leftShift(b, q + 1);
        }

        ans += powerOfTwo(q);
        a -= leftShift(b, q);
    }

    if (ans >= powerOfTwo(31) && isPositive == true)
        return INT_MAX;
    if (ans >= powerOfTwo(31) && isPositive == false)
        return INT_MIN;

    if (isPositive == true)
        return ans;
    else
        return -ans;
}

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}