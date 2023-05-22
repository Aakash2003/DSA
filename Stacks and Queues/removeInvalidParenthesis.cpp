#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
set<string> s;

int minRemoval(string str)
{
    int n = str.length();
    stack<char> s;

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch == '(')
            s.push(ch);
        else if (ch == ')')
        {
            if (s.empty())
                s.push(ch);
            else if (s.top() == ')')
                s.push(ch);
            else if (s.top() == '(')
                s.pop();
        }
    }

    return s.size();
}

void solve(string str, int mini)
{
    int n = str.length();
    if (s.count(str) > 0)
        return;
    else s.insert(str);

    if (mini < 0)
        return;
    else if (mini == 0)
    {
        if (minRemoval(str) == 0)
            ans.push_back(str);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        solve(left + right, mini - 1);
    }
}

vector<string> removeInvalidParentheses(string str)
{
    int n = str.length();
    int mini = minRemoval(str);
    solve(str, mini);
    return ans;
}