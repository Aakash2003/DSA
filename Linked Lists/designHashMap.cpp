#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int key;
    int val;
    Node *next;
    Node(int key, int val) : key(key), val(val), next(NULL) {}
    ~Node() { delete next; }
};

class MyHashMap
{
    Node **buckets;
    int cnt;
    int numbuckets;

private:
    int getBucketIndex(int val)
    {
        string key = to_string(val);
        int n = key.length();
        int hashCode = 0, p = 37;

        for (int i = n - 1; i >= 0; i--)
        {
            hashCode += key[i] * p;
            hashCode %= numbuckets;
            p *= 37;
            p %= numbuckets;
        }

        return hashCode % numbuckets;
    }

    void rehash()
    {
        Node **prev = buckets;
        buckets = new Node *[2 * numbuckets];
        for(int i=0;i<2*numbuckets;i++) buckets[i] = NULL;

        int prevCnt = numbuckets;
        numbuckets *= 2;
        cnt = 0;

        for(int i=0;i<prevCnt;i++)
        {
            Node* head = prev[i];
            while(head!=NULL)
            {
                int key = head->key;
                int value = head->val;
                put(key,value);
                head = head->next;
            }
        }

        for(int i=0;i<prevCnt;i++) 
        {
            Node* head = prev[i];
            delete head;
        }

        delete[] prev;
    }

public:
    MyHashMap()
    {
        cnt = 0;
        numbuckets = (int)(1e2+5);
        buckets = new Node *[numbuckets];
        for (int i = 0; i < numbuckets; i++)
            buckets[i] = NULL;
    }

    ~MyHashMap()
    {
        for (int i = 0; i < numbuckets; i++)
            delete buckets[i];
        delete[] buckets;
    }

    void put(int key, int value)
    {
        int bucketIndex = getBucketIndex(key);
        Node *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->val = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        Node *node = new Node(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        cnt++;

        double loadFactor = (1.0 * cnt) / numbuckets;
        if (loadFactor > 0.7)
            rehash();
    }

    int get(int key)
    {
        int bucketIndex = getBucketIndex(key);
        Node *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
                return head->val;
            head = head->next;
        }

        return -1;
    }

    void remove(int key)
    {
        int bucketIndex = getBucketIndex(key);
        Node *head = buckets[bucketIndex];
        Node *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                    buckets[bucketIndex] = head->next;
                else
                    prev->next = head->next;

                head->next = NULL;
                delete head;
                cnt--;
                return;
            }

            prev = head;
            head = head->next;
        }

        return;
    }
};