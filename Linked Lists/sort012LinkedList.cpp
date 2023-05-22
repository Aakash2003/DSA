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

ListNode *segregate012(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy[3];
    dummy[0] = new ListNode(INT_MIN), dummy[1] = new ListNode(INT_MIN), dummy[2] = new ListNode(INT_MIN);
    ListNode *prev_zero = dummy[0], *prev_one = dummy[1], *prev_two = dummy[2];
    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val == 0)
        {
            prev_zero->next = curr;
            prev_zero = prev_zero->next;
        }
        else if (curr->val == 1)
        {
            prev_one->next = curr;
            prev_one = prev_one->next;
        }
        else
        {
            prev_two->next = curr;
            prev_two = prev_two->next;
        }

        curr = curr->next;
    }

    prev_one->next = dummy[2]->next;
    prev_zero->next = dummy[1]->next;
    prev_two->next = NULL;
    return dummy[0]->next;
}