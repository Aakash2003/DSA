#include <bits/stdc++.h>
using namespace std;

vector<int> calcZArray(string s)
{
    int n = s.length();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
            
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    return z;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    int tn = text.length(), pn = pattern.length();

    string newString = pattern + '$' + text;
    int newLen = newString.length();

    vector<int> z_array = calcZArray(newString);

    for (int i = 0; i < newLen; i++)
    {
        if (z_array[i] == pn)
            cout << i - pn - 1 << " ";
    }

    return 0;
}