#include <bits/stdc++.h>
#define ll long long;
using namespace std;

const int N = 1000000;
int phi[N + 1];

void preprocess()
{
    for (int i = 1; i <= N; i++)
        phi[i] = i;

    for (int i = 2; i <= N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= N; j += i)
            {
                phi[j] = phi[j] / i;
                phi[j] = phi[j] * (i - 1);
            }
        }
    }
}

int main()
{
    int q, n;
    cin >> q;

    preprocess();

    while (q--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }
}