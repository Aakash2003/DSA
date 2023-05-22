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

    ListNode *prev = NULL,*next = NULL;
    ListNode *curr = node;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *mid = findMid(head);
    ListNode *next = mid->next;
    mid->next = NULL;
    next = reverseList(next);

    ListNode *curr1 = head, *curr2 = next;
    bool ans = true;

    while (curr2 != NULL)
    {
        if (curr1->val != curr2->val)
        {
            ans = false;
            break;
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    next = reverseList(next);
    mid->next = next;
    return ans;
}
