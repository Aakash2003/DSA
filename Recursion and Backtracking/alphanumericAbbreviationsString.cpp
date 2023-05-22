#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void abbreviations(string s, string output, int count, int index)
{
    int n = s.length();
    if (index >= n)
    {
        if (count == 0)
            ans.push_back(output);
        else
            ans.push_back(output + to_string(count));
        return;
    }

    if(count>0) abbreviations(s,output+to_string(count)+s[index],0,index+1);
    else abbreviations(s,output+s[index],0,index+1);

    abbreviations(s,output,count+1,index+1);
}