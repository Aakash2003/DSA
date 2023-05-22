#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev, *next;
    };

    void addNode(Node *node)
    {
        Node *nbr = head->next;
        node->next = nbr;
        node->prev = head;
        nbr->prev = node;
        head->next = node;
    }

    void removeNode(Node *node)
    {
        Node *prev_nbr = node->prev;
        Node *next_nbr = node->next;
        prev_nbr->next = next_nbr;
        next_nbr->prev = prev_nbr;
        node->prev = node->next = NULL;
    }

    void moveToFront(Node *node)
    {
        removeNode(node);
        addNode(node);
    }

    map<int, Node *> cache;
    int capacity;
    Node *head, *tail;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.count(key) == 0)
            return -1;
        else
        {
            Node *node = cache[key];
            int val = node->val;
            moveToFront(node);
            return val;
        }
    }

    void put(int key, int val)
    {
        if (cache.count(key) == 0)
        {
            Node *newNode = new Node();
            newNode->key = key;
            newNode->val = val;

            if (cache.size() == capacity)
            {
                Node *lru_node = tail->prev;
                cache.erase(lru_node->key);
                removeNode(lru_node);
            }

            cache[key] = newNode;
            addNode(newNode);
        }
        else
        {
            Node *node = cache[key];
            node->val = val;
            moveToFront(node);
        }
    }
};
