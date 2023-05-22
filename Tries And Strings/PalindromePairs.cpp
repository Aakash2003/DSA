#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int index;
    vector<int> list;
    Node *next[26];

    Node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        index = -1;
        list.clear();
    }
} Node;

void insert(Node *node, string &word, int index)
{
    int n = word.length();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = word[i];
        if (node->next[ch - 'a'] == NULL)
            node->next[ch - 'a'] = new Node();
        if (isPalindrome(word, 0, i))
            node->list.push_back(index);

        node = node->next[ch - 'a'];
    }

    node->list.push_back(index);
    node->index = index;
}

void search(Node *node, vector<string> &words, int i, vector<vector<int>> &ans)
{
    for (int j = 0; j < words[i].size(); j++)
    {

        if (node->index >= 0 && node->index != i && isPalindrome(words[i], j, words[i].size() - 1))
            ans.push_back({i, node->index});

        node = node->next[words[i][j] - 'a'];
        if (node == NULL)
            return;
    }

    for (int j : node->list)
    {

        if (i == j)
            continue;

        ans.push_back({i, j});
    }
}

void remove(Node *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->next[i] != NULL)
            remove(node->next[i]);
    }

    delete node;
}

bool isPalindrome(string &word, int start, int end)
{
    while (start <= end)
    {
        if (word[start] != word[end])
            return false;
        start++, end--;
    }

    return true;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    int n = words.size();
    vector<vector<int>> ans;
    Node *root = new Node();

    for (int i = 0; i < n; i++)
        insert(root, words[i], i);
    for (int i = 0; i < n; i++)
        search(root, words, i, ans);

    remove(root);
    return ans;
}