#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MinStack
{
private:
    stack<ll> s;
    ll mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            mini = val;
        }
        else if (val >= mini)
            s.push(val);
        else
        {
            s.push(val + (val - mini));
            mini = val;
        }
    }

    void pop()
    {
        if (!s.empty())
        {
            if (s.top() >= mini)
                s.pop();
            else
            {
                mini = 2 * mini - (ll)s.top();
                s.pop();
            }
        }
    }

    int top()
    {
        if (s.empty())
            return -1;
        else
        {
            if (s.top() >= mini)
                return (int)s.top();
            else
                return (int)mini;
        }
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        else
            return (int)mini;
    }
};