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

ListNode *reverseList(ListNode *node)
{
    if (node == NULL || node->next == NULL)
        return node;

    ListNode *prev = NULL;
    ListNode *curr = node;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    ListNode* curr1 = reverseList(l1);
    ListNode* curr2 = reverseList(l2);
    ListNode* dummy = new ListNode(-1);
    ListNode* itr = dummy;
    int carry = 0;

    while(curr1!=NULL||curr2!=NULL||carry!=0)
    {
        int val1 = 0,val2 = 0;
        if(curr1!=NULL) val1 = curr1->val;
        if(curr2!=NULL) val2 = curr2->val;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum/10;

        itr->next = new ListNode(digit);
        itr = itr->next;

        if(curr1!=NULL) curr1 = curr1->next;
        if(curr2!=NULL) curr2 = curr2->next;
    }

    return reverseList(dummy->next);
}