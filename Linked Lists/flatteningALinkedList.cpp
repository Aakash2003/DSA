#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr), bottom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), bottom(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *bottom) : val(x), next(next), bottom(bottom) {}
};

ListNode *mergeTwoLists(ListNode *&list1, ListNode *&list2)
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
            prev->bottom = curr1;
            curr1 = curr1->bottom;
        }
        else
        {
            prev->bottom = curr2;
            curr2 = curr2->bottom;
        }

        prev = prev->bottom;
    }

    if (curr1 != NULL)
        prev->bottom = curr1;
    if (curr2 != NULL)
        prev->bottom = curr2;

    return dummy->bottom;
}

ListNode *flatten(ListNode *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}