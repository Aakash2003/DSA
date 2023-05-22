#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    typedef struct Node{
        Node* next[26];
        bool isEnding;

        Node()
        {
            isEnding = false;
            for(int i=0;i<26;i++) next[i] = NULL;
        }
    }Node;

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node* curr = root;

        for(int i=0;i<n;i++)
        {
            char ch = word[i];
            if(curr->next[ch-'a']==NULL) curr->next[ch-'a'] = new Node();
            curr = curr->next[ch-'a'];
        }

        curr->isEnding = true;
    }
    
    bool search(string word) {

        int n = word.length();
        Node* curr = root;

        for(int i=0;i<n;i++)
        {
            char ch = word[i];
            if(curr->next[ch-'a']==NULL) return false;
            curr = curr->next[ch-'a'];
        }

        return curr->isEnding;
    }
    
    bool startsWith(string prefix) {    
        int n = prefix.length();
        Node* curr = root;

        for(int i=0;i<n;i++)
        {
            char ch = prefix[i];
            if(curr->next[ch-'a']==NULL) return false;
            curr = curr->next[ch-'a'];
        }

        return true;
    }
};