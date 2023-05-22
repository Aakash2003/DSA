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

ListNode *temp_head = NULL, *temp_tail = NULL;

void AddFirst(ListNode *node)
{
    if (temp_head == NULL)
    {
        temp_head = node;
        temp_tail = node;
    }
    else
    {
        node->next = temp_head;
        temp_head = node;
    }
}

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int len = length(head);
    ListNode *original_head = NULL, *original_tail = NULL;
    ListNode *curr = head;

    while (len >= k)
    {
        int x = k;
        while (x > 0)
        {
            ListNode *next = curr->next;
            curr->next = NULL;
            AddFirst(curr);
            curr = next;
            x--;
        }

        if (original_head == NULL)
        {
            original_head = temp_head;
            original_tail = temp_tail;
        }
        else
        {
            original_tail->next = temp_head;
            original_tail = temp_tail;
        }

        temp_head = NULL, temp_tail = NULL;
        len -= k;
    }

    original_tail->next = curr;
    return original_head;
}