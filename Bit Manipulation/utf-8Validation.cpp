#include <bits/stdc++.h>
using namespace std;

int rightShift(int a, int x)
{
    return (a >> x);
}

bool validUtf8(vector<int> &data)
{
    int remaining_bytes = 0;
    for (int v : data)
    {
        if (remaining_bytes == 0)
        {
            if (rightShift(v, 7) == 0b0)
                remaining_bytes = 0;
            else if (rightShift(v, 5) == 0b110)
                remaining_bytes = 1;
            else if (rightShift(v, 4) == 0b1110)
                remaining_bytes = 2;
            else if (rightShift(v, 3) == 0b11110)
                remaining_bytes = 3;
        }
        else
        {
            if (rightShift(v, 6) == 0b10)
                remaining_bytes--;
            else
                return false;
        }
    }

    if (remaining_bytes == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];

    string ans[] = {"False", "True"};
    cout << ans[validUtf8(data)] << endl;
}