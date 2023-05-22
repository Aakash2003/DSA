#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> primes;
    bool arr[n + 1];

    for (int i = 0; i <= n; i++)
        arr[i] = true;

    arr[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                arr[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    int L, R;
    cin >> L >> R;
    int nums[R - L + 1];
    for (int i = L; i <= R; i++)
        nums[i - L] = true;

    vector<int> primes = sieve(sqrt(R));

    for (int p : primes)
    {
        int start = (L / p) * p;
        if (start % p != 0)
            start += p;

        for (int j = start; j <= R; j += p)
            nums[j - L] = false;
    }

    for (int i = L; i <= R; i++)
    {
        if (nums[i - L] == true)
            cout << i << " ";
    }
}