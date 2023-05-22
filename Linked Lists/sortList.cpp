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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *prev = dummy;

    ListNode *curr1 = list1, *curr2 = list2;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->val < curr2->val)
        {
            prev->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            prev->next = curr2;
            curr2 = curr2->next;
        }

        prev = prev->next;
    }

    if (curr1 != NULL)
        prev->next = curr1;
    if (curr2 != NULL)
        prev->next = curr2;

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = findMid(head);
    ListNode *next = mid->next;
    mid->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(next);
    return mergeTwoLists(l1, l2);
}