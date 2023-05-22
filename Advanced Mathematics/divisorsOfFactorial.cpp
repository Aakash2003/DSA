#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int m = (int)(1e9+7);
vector<int> primes;

void preprocess()
{
    int N = 50000;
    bool nums[N + 1];

    for (int i = 1; i <= N; i++)
        nums[i] = true;

    nums[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (nums[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
                nums[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (nums[i] == true)
            primes.push_back(i);
    }
}

ll divisor_count(ll n)
{
    ll ans = 1;
    int size = primes.size();

    for (int i = 0; i < size; i++)
    {
        if (primes[i] <= n)
        {
            int p = primes[i];
            int count = 0;

            while (p <= n)
            {
                count += n / p;
                p *= primes[i];
            }

            ans = ((ans % m) * ((count + 1) % m)) % m;
        }
        else
            break;
    }

    return ans;
}

int main()
{
    int t;
    ll n;
    cin >> t;
    preprocess();

    while (t--)
    {
        cin >> n;
        cout << divisor_count(n) << endl;
    }

    return 0;
}