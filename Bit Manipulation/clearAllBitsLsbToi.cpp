#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(int x)
{
    return (1 << x);
}

void clearlsbToiBits(int &n, int i)
{
    int mask = powerOfTwo(64) - 1;
    mask = mask ^ (powerOfTwo(i+1) - 1);
    n = n & mask;
}