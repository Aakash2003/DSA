#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementLeft(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && heights[i] <= heights[s.top()])
            s.pop();

        if (s.empty())
            left[i] = -1;
        else
            left[i] = s.top();

        s.push(i);
    }

    return left;
}

vector<int> nextSmallerElementRight(vector<int> &heights)
{
    int n = heights.size();
    vector<int> right(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[i] <= heights[s.top()])
            s.pop();

        if (s.empty())
            right[i] = n;
        else
            right[i] = s.top();

        s.push(i);
    }

    return right;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> left = nextSmallerElementLeft(heights);
    vector<int> right = nextSmallerElementRight(heights);

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxi = max(maxi, area);
    }

    return maxi;
}