#include <bits/stdc++.h>
using namespace std;

int findTheWinner(int n, int k)
{
    if (n == 1)
        return 1;

    int x = findTheWinner(n - 1, k);
    int y = ((x + k - 1) % n) + 1;
    return y;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findTheWinner(n, k) << endl;
}