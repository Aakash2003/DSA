#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *next[26];
    int cnt;

    Node()
    {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} Node;

void insert(Node *curr, string &s, int index)
{
    int n = s.length();
    curr->cnt += 1;
    if (index >= n)
        return;

    int nextIndex = (int)(s[index] - 'a');
    if (curr->next[nextIndex] == NULL)
        curr->next[nextIndex] = new Node();

    insert(curr->next[nextIndex], s, index + 1);
}

int search(Node *curr, string &s, int index)
{
    int n = s.length();
    if (curr == NULL)
        return 0;
    if (index >= n)
        return curr->cnt;

    int nextIndex = (int)(s[index] - 'a');
    return search(curr->next[nextIndex], s, index + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    Node *root = new Node();

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insert(root, word, 0);
    }

    while (q--)
    {
        string s;
        cin >> s;
        cout << search(root, s, 0) << endl;
    }
}
