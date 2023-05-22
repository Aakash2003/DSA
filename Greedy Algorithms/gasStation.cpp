#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int start = 0, balance = 0;
    int deficit = 0;

    for (int i = 0; i < n; i++)
    {
        balance += (gas[i] - cost[i]);
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
        return start;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << canCompleteCircuit(gas, cost) << endl;
}