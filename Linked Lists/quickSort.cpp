#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int length(ListNode *node)
{
    int len = 0;
    ListNode *curr = node;

    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }

    return len;
}

vector<ListNode *> segregate(ListNode *node, int pivotIndex)
{
    ListNode *dummy_small = new ListNode(INT_MIN);
    ListNode *dummy_large = new ListNode(INT_MIN);
    ListNode *small_prev = dummy_small, *large_prev = dummy_large;
    ListNode *curr = node, *pivot = node;

    while (pivotIndex--)
        pivot = pivot->next;

    while (curr != NULL)
    {
        if (curr != pivot)
        {
            if (curr->val <= pivot->val)
            {
                small_prev->next = curr;
                small_prev = small_prev->next;
            }
            else
            {
                large_prev->next = curr;
                large_prev = large_prev->next;
            }
        }

        curr = curr->next;
    }

    small_prev->next = NULL, large_prev->next = NULL, pivot->next = NULL;
    return {dummy_small->next, pivot, dummy_large->next};
}

pair<ListNode *, ListNode *> mergeSortedLists(pair<ListNode *, ListNode *> left, ListNode *pivot, pair<ListNode *, ListNode *> right)
{
    ListNode *head = NULL, *tail = NULL;
    if (left.first != NULL && right.first != NULL)
    {
        left.second->next = pivot;
        pivot->next = right.first;
        head = left.first, tail = right.second;
    }
    else if (left.first != NULL && right.first == NULL)
    {
        head = left.first;
        left.second->next = pivot;
        tail = pivot;
    }
    else if (left.first == NULL && right.first != NULL)
    {
        head = pivot;
        pivot->next = right.first;
        tail = right.second;
    }
    else
        head = tail = pivot;

    return {head, tail};
}

pair<ListNode *, ListNode *> quickSort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return {head, head};

    int len = length(head);
    int pivotIndex = len / 2;

    vector<ListNode *> segregateList = segregate(head, pivotIndex);

    pair<ListNode *, ListNode *> leftList = quickSort(segregateList[0]);
    pair<ListNode *, ListNode *> rightList = quickSort(segregateList[2]);
    return mergeSortedLists(leftList, segregateList[1], rightList);
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    return quickSort(head).first;
}