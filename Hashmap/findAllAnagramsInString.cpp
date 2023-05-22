#include <bits/stdc++.h>
using namespace std;

bool compare(map<int, int> &p1, map<int, int> &s1)
{
    for (auto i : s1)
    {
        if (p1[i.first] != s1[i.first])
            return false;
    }

    return true;
}

vector<int> findAnagrams(string s, string p)
{
    int tn = s.length(), pn = p.length();
    map<int, int> s1;
    map<int, int> p1;
    vector<int> ans;

    for (int i = 0; i < pn; i++)
        p1[p[i]]++, s1[s[i]]++;

    int i = pn;
    while (i < tn)
    {
        if (compare(p1, s1))
            ans.push_back(i - pn);

        char ch1 = s[i];
        s1[ch1]++;

        char ch2 = s[i - pn];
        if (s[ch2] == 1)
            s1.erase(ch2);
        else
            s1[ch2]--;

        i++;
    }

    if (compare(p1, s1))
        ans.push_back(i - pn);

    return ans;
}

int main()
{
}