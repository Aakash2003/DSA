#include <bits/stdc++.h>
using namespace std;

void heapSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (nums[childIndex] > nums[parentIndex])
                swap(nums[childIndex], nums[parentIndex]);
            else
                break;

            childIndex = parentIndex;
        }
    }

    int size = n;

    while (size > 1)
    {
        swap(nums[0], nums[size - 1]);
        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1, rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {
            int maxIndex = parentIndex;
            if (leftChildIndex < size && nums[maxIndex] < nums[leftChildIndex])
                maxIndex = leftChildIndex;
            if (rightChildIndex < size && nums[maxIndex] < nums[rightChildIndex])
                maxIndex = rightChildIndex;

            if (maxIndex == parentIndex)
                break;

            swap(nums[maxIndex], nums[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1, rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    heapSort(nums);

    for (auto i : nums)
        cout << i << " ";
}