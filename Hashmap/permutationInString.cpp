#include<bits/stdc++.h>
using namespace std;

bool compare(map<char, int> &mp1, map<char, int> &mp2)
{
    for (auto i : mp2)
    {
        if (mp1[i.first] != mp2[i.first])
            return false;
    }

    return true;
}

bool checkInclusion(string s1, string s2)
{
    int n = s1.length(),m = s2.length();
    if(m<n) return false;

    map<char,int> mp1,mp2;
    int j = 0;
    for(int i=0;i<n;i++) mp1[s1[i]]++;
    
    for(int i=0;i<m;i++)
    {
        char ch1 = s2[i];
        mp2[ch1]++;

        if(mp1.size()==mp2.size())
        {
            if(compare(mp1,mp2)) return true;
        }
        else if(mp2.size()>mp1.size())
        {
            while(j<=i && mp2.size()>mp1.size())
            {
                char ch2 = s2[j];
                mp2[ch2]--;
                if(mp2[ch2]==0) mp2.erase(ch2);
                j++;
            }
        }
    }

    return false;
}