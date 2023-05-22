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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode *findMid(ListNode *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *curr = head;
    ListNode *slow = head, *fast = head;
    ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;
    return slow;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return new TreeNode(head->val);

    ListNode *mid = findMid(head);
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
}