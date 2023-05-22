#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, char delimiter)
{
    vector<string> ans;
    stringstream ss(s);
    string output;

    while (getline(ss, output, delimiter))
        ans.push_back(output);

    return ans;
}

bool wordPattern(string pattern, string s)
{
    vector<string> words = split(s, ' ');
    int n = pattern.length(), m = words.size();

    if (n != m)
        return false;

    map<char, string> mp1;
    map<string, bool> mp2;

    for (int i = 0; i < n; i++)
    {
        char ch = pattern[i];

        if (mp1.count(ch) == 0)
        {
            if (mp2.count(words[i]) > 0)
                return false;
            else
            {
                mp2[words[i]] = true;
                mp1[ch] = words[i];
            }
        }
        else
        {
            string s = mp1[ch];
            if (s != words[i])
                return false;
        }
    }

    return true;
}

int main()
{
    string pattern, s;
    cin >> pattern >> s;
}