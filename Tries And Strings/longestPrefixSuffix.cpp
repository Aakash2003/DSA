#include<bits/stdc++.h>
using namespace std;

int lps(string &s)
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

int main()
{
    string s;
    cin>>s;
    cout<<lps(s)<<endl;
}