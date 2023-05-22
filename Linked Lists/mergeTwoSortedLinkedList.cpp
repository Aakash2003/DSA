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