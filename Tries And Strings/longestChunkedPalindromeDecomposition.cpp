#include <bits/stdc++.h>
using namespace std;

int longestDecomposition(string text)
{
    int n = text.length();
    int ans = 0;

    string left = "", right = "";
    for (int i = 0; i < n; i++)
    {
        left = left + text[i];
        right = text[n - i - 1] + right;

        if (left == right)
        {
            ans++;
            left = right = "";
        }
    }

    return ans;
}