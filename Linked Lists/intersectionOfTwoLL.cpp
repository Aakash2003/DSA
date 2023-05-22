#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *curr1 = headA;
    ListNode *curr2 = headB;

    while (curr1 != curr2)
    {
        if (curr1 == NULL)
            curr1 = headB;
        else
            curr1 = curr1->next;

        if (curr2 == NULL)
            curr2 = headA;
        else
            curr2 = curr2->next;
    }

    return curr1;
}