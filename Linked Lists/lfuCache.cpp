#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode
{
    int key, val, cnt;
    ListNode *prev;
    ListNode *next;
    ListNode(int key, int val) : key(key), val(val), cnt(1), prev(nullptr), next(nullptr) {}
}ListNode;

typedef struct List
{
    int size;
    ListNode* head;
    ListNode* tail;

    List()
    {
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(ListNode* node)
    {
        ListNode* next = head->next;
        node->next = next;
        node->prev = head;
        head->next = node;
        next->prev = node;
        size++;
    }

    void removeNode(ListNode* node)
    {
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
}List;

class LFUCache
{
private:
    map<int,ListNode*> mp1;
    map<int,List*> mp2;
public:
    LFUCache(int capacity)
    {
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }
};