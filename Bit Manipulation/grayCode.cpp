#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(int x)
{
    return (1 << x);
}

vector<int> grayCode(int n)
{
    if (n == 0)
        return {0};
    else if (n == 1)
        return {0, 1};

    vector<int> a = grayCode(n - 1);
    int size = a.size();

    vector<int> ans;

    for (int i = 0; i < size; i++)
        ans.push_back(a[i]);
    for (int i = size - 1; i >= 0; i--)
        ans.push_back(a[i] + powerOfTwo(n - 1));

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans = grayCode(n);

    for (auto i : ans)
        cout << i << " ";
}