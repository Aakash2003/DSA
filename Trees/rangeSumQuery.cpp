#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    vector<int> tree;
    vector<int> nums;

    void build(int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(start, mid, 2 * node + 1);
        build(mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int start, int end, int index, int val, int node)
    {
        if (start == end)
        {
            tree[node] = nums[start] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid)
            update(start, mid, index, val, 2 * node + 1);
        else
            update(mid + 1, end, index, val, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int start, int end, int ql, int qr, int node)
    {
        if (ql <= start && qr >= end)
            return tree[node];
        if (qr < start || ql > end)
            return 0;

        int mid = start + (end - start) / 2;
        return query(start, mid, ql, qr, 2 * node + 1) + query(mid + 1, end, ql, qr, 2 * node + 2);
    }

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        int n = nums.size();
        tree = vector<int>(4 * n);
        build(0, n - 1, 0);
    }

    void update(int index, int val)
    {
        int n = nums.size();
        update(0, n - 1, index, val, 0);
    }

    int sumRange(int left, int right)
    {
        int n = nums.size();
        return query(0, n - 1, left, right, 0);
    }
};
