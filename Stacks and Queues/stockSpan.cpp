#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int> &price)
{
    int n = price.size();
    vector<int> span(n);
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        while(!s.empty() && price[i] >= price[s.top()]) s.pop();

        if(s.empty()) span[i] = i+1;
        else span[i] = i-s.top();

        s.push(i);
    }

    return span;
}