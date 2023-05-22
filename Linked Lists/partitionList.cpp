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

ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy_left = new ListNode(INT_MIN);
    ListNode *dummy_right = new ListNode(INT_MIN);
    ListNode *left_prev = dummy_left, *right_prev = dummy_right;
    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val < x)
        {
            left_prev->next = curr;
            left_prev = left_prev->next;
        }
        else
        {
            right_prev->next = curr;
            right_prev = right_prev->next;
        }

        curr = curr->next;
    }

    left_prev->next = dummy_right->next;
    right_prev->next = NULL;
    return dummy_left->next;
}