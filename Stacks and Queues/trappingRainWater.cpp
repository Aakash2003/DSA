#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    stack<int> s;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && height[i] >= height[s.top()])
        {
            int right = i;
            int size = height[s.top()];
            s.pop();

            if (s.empty())
                break;

            int left = s.top();
            int width = right - left - 1;
            
            ans += (min(height[left], height[right]) - size) * width;
        }

        s.push(i);
    }

    return ans;
}