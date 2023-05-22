#include <bits/stdc++.h>
using namespace std;

const int n = 1000000;
bool prime[n + 1];

void sieve()
{
    for (int i = 1; i <= n; i++)
        prime[i] = true;

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
}

vector<int> primeNumbersTillN(int N)
{
    vector<int> ans;
    sieve();
    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans = primeNumbersTillN(n);
    for (auto i : ans)
        cout << i << " ";
}