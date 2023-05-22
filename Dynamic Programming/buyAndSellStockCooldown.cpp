#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int b, s, c;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            b = -prices[0], s = 0, c = 0;
        else
        {
            int B = 0, S = 0, C = 0;

            if (c - prices[i] > b)
                B = c - prices[i];
            else
                B = b;

            if (b + prices[i] > s)
                S = b + prices[i];
            else
                S = s;

            if (s > c)
                C = s;
            else
                C = c;

            b = B, s = S, c = C;
        }
    }

    return s;
}