#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *next[26];
    int maxSubtree;

    Node()
    {
        maxSubtree = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} Node;

void insert(Node *curr, pair<string, int> &databaseEntry, int index)
{
    int n = databaseEntry.first.length();
    if (index >= n)
    {
        curr->maxSubtree = databaseEntry.second;
        return;
    }

    curr->maxSubtree = max(curr->maxSubtree, databaseEntry.second);
    int nextIndex = (int)(databaseEntry.first[index] - 'a');
    if (curr->next[nextIndex] == NULL)
    {
        curr->next[nextIndex] = new Node();
    }

    insert(curr->next[nextIndex], databaseEntry, index + 1);
}

int query(Node *curr, string &txt, int index)
{
    int n = txt.length();
    if (curr == NULL)
        return -1;
    if (index >= n)
        return curr->maxSubtree;

    int nextIndex = (int)(txt[index] - 'a');
    return query(curr->next[nextIndex], txt, index + 1);
}

int main()
{
    int n, q;
    cin >> n >> q;
    pair<string, int> database[n];

    for (int i = 0; i < n; i++)
        cin >> database[i].first >> database[i].second;

    Node *root = new Node();

    for (int i = 0; i < n; i++)
        insert(root, database[i], 0);

    while (q--)
    {
        string txt;
        cin >> txt;
        cout << query(root, txt, 0) << endl;
    }

    return 0;
}