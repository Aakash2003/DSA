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

ListNode *findMid(ListNode *node)
{
    if (node == NULL || node->next == NULL)
        return node;

    ListNode *slow = node;
    ListNode *fast = node;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *reverseList(ListNode *node)
{
    if (node == NULL || node->next == NULL)
        return node;

    ListNode *prev = NULL;
    ListNode *curr = node;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    ListNode *mid = findMid(head);
    ListNode *next = mid->next;
    mid->next = NULL;
    next = reverseList(next);

    ListNode *curr1 = head, *curr2 = next;
    ListNode *next1 = NULL, *next2 = NULL;

    while (curr2 != NULL)
    {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }
}