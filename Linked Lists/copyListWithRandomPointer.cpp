#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *random) : val(x), next(next), random(random) {}
};

void copyList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        ListNode *node = new ListNode(curr->val);
        curr->next = node;
        node->next = next;
        curr = next;
    }
}

void copyRandomPointers(ListNode *head)
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *random = curr->random;
        if (random != NULL)
            curr->next->random = random->next;

        if (curr->next != NULL)
            curr = curr->next->next;
    }
}

ListNode *extractDeepCopy(ListNode *head)
{
    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *prev = dummy, *curr = head;

    while (curr != NULL)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev = prev->next;
        curr = curr->next;
    }

    return dummy->next;
}

ListNode *copyRandomList(ListNode *head)
{
    if (head == NULL)
        return NULL;

    copyList(head);
    copyRandomPointers(head);
    return extractDeepCopy(head);
}