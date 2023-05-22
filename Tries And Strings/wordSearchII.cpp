#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

typedef struct Node
{
    Node *next[26];
    string s;
    int cnt;

    Node()
    {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} Node;

void insert(Node *node, string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (node->next[ch - 'a'] == NULL)
        {
            node->next[ch - 'a'] = new Node();
            node->cnt++;
        }
        node = node->next[ch - 'a'];
    }

    node->s = s;
}

void dfs(Node *node, vector<vector<char>> &board, vector<vector<bool>> &visited, vector<string> &ans, int x, int y)
{
    char ch = board[x][y];
    Node *next = node->next[ch - 'a'];
    
    if (next == NULL || visited[x][y] == true)
        return;
    int n = board.size(), m = board[0].size();

    if (next->s != "")
    {
        ans.push_back(next->s);
        next->s = "";
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && node->cnt != 0)
            dfs(next, board, visited, ans, newX, newY);
    }

    visited[x][y] = false;
    if (next->cnt == 0)
        node->cnt -= 1;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    int n = board.size(), m = board[0].size();
    Node *root = new Node();
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (string s : words)
        insert(root, s);

    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dfs(root, board, visited, ans, i, j);
    }

    return ans;
}