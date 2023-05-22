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

void addLast(ListNode *node)
{
    if (temp_tail == NULL)
    {
        temp_head = NULL;
        temp_tail = NULL;
    }
    else
    {
        temp_tail->next = node;
        temp_tail = node;
    }
}

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = NULL;
        if (temp_tail == NULL || temp_tail->val != curr->val)
            addLast(curr);
            
        curr = curr->next;
    }

    return temp_head;
}