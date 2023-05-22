#include <bits/stdc++.h>
using namespace std;

int mex(multiset<int> &vals)
{
    int MEX = 0;
    while (vals.find(MEX) != vals.end())
        MEX++;

    return MEX;
}

int main()
{
    int n = 10;
    int grundy[n + 1];

    multiset<int> vals;

    for (int i = 0; i <= 3; i++)
    {
        grundy[i] = i;
        vals.insert(i);
    }

    for (int i = 4; i <= n; i++)
    {
        vals.erase(vals.find(grundy[i - 4]));
        grundy[i] = mex(vals);
        vals.insert(grundy[i]);
    }

    for (int i = 0; i <= n; i++)
        cout << grundy[i] << " ";
    return 0;
}