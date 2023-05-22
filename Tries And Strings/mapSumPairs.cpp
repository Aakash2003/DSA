#include <bits/stdc++.h>
using namespace std;

class MapSum
{
private:
    typedef struct Node
    {
        Node *next[26];
        int score;

        Node()
        {
            score = 0;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    } Node;


public:
    map<string,int> mp;
    Node* root;

    MapSum()
    {
        root = new Node();
    }

    void insert(string key, int val)
    {
        int n = key.length();
        int dx = val-mp[key];
        mp[key] = val;
        Node* curr = root;

        for(int i=0;i<n;i++)
        {
            char ch = key[i];
            if(curr->next[ch-'a']==NULL) curr->next[ch-'a'] = new Node();

            curr = curr->next[ch-'a'];
            curr->score += dx;
        }
    }

    int sum(string prefix)
    {
        int n = prefix.length();
        Node* curr = root;

        for(int i=0;i<n;i++)
        {
            char ch = prefix[i];
            if(curr->next[ch-'a']==NULL) return 0;
            curr = curr->next[ch-'a'];
        }

        return curr->score;
    }
};