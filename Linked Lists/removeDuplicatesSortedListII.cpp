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

ListNode *deleteDuplicates(ListNode *head)
{
    if(head==NULL||head->next==NULL) return head;

    ListNode* dummy = new ListNode(INT_MIN);
    ListNode* itr = dummy;
    itr->next = head;
    ListNode* curr = head->next;

    while(curr!=NULL)
    {
        bool flag = false;
        while(curr!=NULL && itr->next->val==curr->val)
        {
            flag = true;
            curr = curr->next;
        }

        if(flag==true) itr->next = curr;
        else itr = itr->next;

        if(curr!=NULL) curr = curr->next;
    }

    return dummy->next;
}