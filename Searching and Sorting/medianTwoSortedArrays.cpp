#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    if (m < n)
        return findMedianSortedArrays(nums2, nums1);

    int start = 0, end = n;
    int total = n + m;

    while (start <= end)
    {
        int c1 = start + (end - start) / 2;
        int c2 = (total + 1) / 2 - c1;
        int left1, left2, right1, right2;

        if (c1 == 0)
            left1 = INT_MIN;
        else
            left1 = nums1[c1 - 1];

        if (c2 == 0)
            left2 = INT_MIN;
        else
            left2 = nums2[c2 - 1];

        if (c1 == n)
            right1 = INT_MAX;
        else
            right1 = nums1[c1];

        if (c2 == m)
            right2 = INT_MAX;
        else
            right2 = nums2[c2];

        if (left1 <= right2 && left2 <= right1)
        {
            double median = 0.0;

            if (total & 1)
                median = max(left1, left2);
            else
                median = (max(left1, left2) + min(right1, right2)) / 2.0;

            return median;
        }
        else if (left1 > right2)
            end = c1 - 1;
        else if (left2 > right1)
            start = c1 + 1;
    }
}

int main()
{
}