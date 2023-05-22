#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s, int k)
{
    int n = s.length();
    int maxi = 0;
    map<char, int> mp;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i];
        mp[ch1]++;

        if (mp.size() <= k)
            maxi = max(maxi, i - j + 1);
        else if (mp.size() > k)
        {
            while (j <= i && mp.size() > k)
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
    int k;
    cin >> s >> k;
    cout << lengthOfLongestSubstring(s, k) << endl;
}
