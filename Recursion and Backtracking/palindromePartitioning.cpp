#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool isPalindrome(string s)
{
    int n = s.length();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        if (s[start] != s[end])
            return false;
        
        start++,end--;
    }

    return true;
}

void palindrome_partition(string s, vector<string> &output)
{
    int n = s.length();
    if (n == 0)
    {
        ans.push_back(output);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string prefix = s.substr(0, i + 1);
        string remaining = s.substr(i + 1);
        if (isPalindrome(prefix))
        {
            output.push_back(prefix);
            palindrome_partition(remaining,output);
            output.pop_back();
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<string> output;
    palindrome_partition(s, output);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}