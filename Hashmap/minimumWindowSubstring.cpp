#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.length(), m = t.length();
    map<char, int> mp1, mp2;
    for (int i = 0; i < m; i++)
        mp1[t[i]]++;

    string ans;
    int cnt = 0, mini = INT_MAX;
    for (int i = 0, j = 0; i < n; i++)
    {
        char c1 = s[i];
        if (mp1.count(c1) > 0)
        {
            mp2[c1]++;
            if (mp2[c1] <= mp1[c1])
                cnt++;
        }

        if (cnt >= m)
        {
            while (mp1.count(s[j]) == 0 || mp2[s[j]] > mp1[s[j]])
            {
                mp2[s[j]]--;
                j++;
            }

            if (i - j + 1 < mini)
                mini = i - j + 1, ans = s.substr(j, mini);
        }
    }

    return ans;
}