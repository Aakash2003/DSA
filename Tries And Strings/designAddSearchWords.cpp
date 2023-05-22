#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
private:
    typedef struct Node
    {
        Node *next[26];
        bool isEnding;

        Node()
        {
            isEnding = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    } Node;

    bool find(Node *node, string word, int index)
    {
        int n = word.length();
        if (index == n)
            return node->isEnding;

        char ch = word[index];

        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->next[i] != NULL && find(node->next[i], word, index + 1) == true)
                    return true;
            }

            return false;
        }
        else
        {
            if (node->next[ch - 'a'] == NULL)
                return false;
            else
                return find(node->next[ch - 'a'], word, index + 1);
        }

        return true;
    }

public:
    Node *root;

    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        int n = word.length();
        Node *curr = root;

        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (curr->next[ch - 'a'] == NULL)
                curr->next[ch - 'a'] = new Node();
            curr = curr->next[ch - 'a'];
        }

        curr->isEnding = true;
    }

    bool search(string word)
    {
        int index = 0;
        return find(root, word, index);
    }
};