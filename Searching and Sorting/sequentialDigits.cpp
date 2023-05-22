#include <bits/stdc++.h>
using namespace std;

vector<int> sequentialDigits(int low, int high)
{
}

int main()
{
    int low, high;
    cin >> low >> high;
    vector<int> ans = sequentialDigits(low, high);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}