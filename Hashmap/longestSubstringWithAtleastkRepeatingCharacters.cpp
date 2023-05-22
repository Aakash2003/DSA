#include <bits/stdc++.h>
using namespace std;

bool freqK(map<char, int> &mp, int k)
{
    for (auto i : mp)
    {
        if (i.second < k)
            return false;
    }

    return true;
}

int longestSubstring(string s, int k)
{
    int n = s.length();
    int maxi = 0;
    map<char, int> mp;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i];
        mp[ch1]++;

        while (!freqK(mp, k) && j <= i)
        {
            char ch2 = s[j];
            mp[ch2]--;
            if (mp[ch2] == 0)
                mp.erase(ch2);
            j++;
        }

        maxi = max(maxi, i - j + 1);
    }

    return maxi;
}