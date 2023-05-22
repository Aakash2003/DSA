#include<bits/stdc++.h>
using namespace std;

int Lps(string s)
{
    int n = s.length();
    vector<int> lps(n);

    int j = 0;
    for(int i=1;i<n;i++)
    {
        while(j>0 && s[i]!=s[j]) j = lps[j-1];

        if(s[i]==s[j]) j++;
        lps[i] = j;
    }

    return lps[n-1];
}

string reverse(string s)
{
    string ans = string(s.rbegin(),s.rend());
    return ans;
}

string shortestPalindrome(string s)
{
    string newString = s+'$'+reverse(s);
    int lps = Lps(newString);
    string ans = reverse(s.substr(lps))+s;
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<shortestPalindrome(s)<<endl;
}