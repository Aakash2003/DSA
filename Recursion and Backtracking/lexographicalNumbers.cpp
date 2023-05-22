#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> ans;

void dfs(int a, int n)
{
    if (a > n)
        return;

    ans.push_back(a);
    for (int b = 0; b <= 9; b++)
        dfs(10 * a + b, n);
}

int main()
{
    int n;
    cin >> n;

    for (int a = 1; a <= 9; a++)
        dfs(a, n);

    for (auto i : ans)
        cout << i << " ";
}