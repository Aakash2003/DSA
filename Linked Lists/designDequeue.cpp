#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val) : val(val), prev(NULL), next(NULL) {}
    Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
    ~Node() { delete next; }
};

class MyCircularDeque
{
    Node *head, *tail;
    int size;
    int k;

public:
    MyCircularDeque(int k)
    {
        head = new Node(INT_MIN);
        tail = new Node(INT_MIN);
        head->next = tail;
        tail->prev = head;
        size = 0;
        this->k = k;
    }

    bool insertFront(int value)
    {
        if (size == k)
            return false;
            
        Node *newNode = new Node(value);
        Node *next = head->next;
        newNode->prev = head;
        newNode->next = next;
        head->next = newNode;
        next->prev = newNode;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == k)
            return false;

        Node *newNode = new Node(value);
        Node *prev = tail->prev;
        newNode->next = tail;
        newNode->prev = prev;
        prev->next = newNode;
        tail->prev = newNode;
        size++;
        return true;
    }

    bool deleteFront()
    {
        Node *node = head->next;
        Node *next = node->next;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
    }

    int getFront()
    {
        if (size > 0)
            return head->next->val;
        else
            return -1;
    }

    int getRear()
    {
        if (size > 0)
            return tail->prev->val;
        else
            return -1;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (size == k)
            return true;
        else
            return false;
    }
};
