#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int b, s;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            b = -prices[0], s = 0;
        else
        {
            int B = 0, S = 0;

            if (s - prices[i] > b)
                B = s - prices[i];
            else
                B = b;

            if (b + prices[i] - fee > s)
                S = b + prices[i] - fee;
            else
                S = s;

            b = B, s = S;
        }
    }

    return s;
}

int main()
{
}