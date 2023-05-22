#include <bits/stdc++.h>
using namespace std;

bool isRepeating(map<char, int> &mp)
{
    for (auto i : mp)
    {
        if (i.second > 1)
            return false;
    }

    return true;
}

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxi = 0;
    map<char, int> mp;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i];
        mp[ch1]++;

        if (isRepeating(mp))
            maxi = max(maxi, i - j + 1);
        else
        {
            while (!isRepeating(mp) && j <= i)
            {
                char ch2 = s[j];
                mp[ch2]--;
                if (mp[ch2] == 0)
                    mp.erase(ch2);
                j++;
            }
        }
    }

    return maxi;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
}