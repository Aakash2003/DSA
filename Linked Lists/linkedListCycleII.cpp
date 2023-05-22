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

ListNode *detectCycle(ListNode *head)
{
    if(head==NULL||head->next==NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }

    if(slow!=fast) return NULL;

    slow = head;

    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}