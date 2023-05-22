#include <bits/stdc++.h>
using namespace std;

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

void insert(Node *curr, string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (curr->next[ch - 'a'] == NULL)
            curr->next[ch - 'a'] = new Node();
        curr = curr->next[ch - 'a'];
        if (curr->isEnding == true)
            return;
    }

    curr->isEnding = true;
}

string searchPrefix(Node *curr, string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (curr->next[ch - 'a'] == NULL)
        {
            if(curr->isEnding==true) return word.substr(0,i+1);
            else return "";
        }
    
        curr = curr->next[ch - 'a'];
        if (curr->isEnding == true)
            return word.substr(0, i + 1);
    }

    return "";
}

vector<string> split(string &s, char delimiter)
{
    vector<string> ans;
    stringstream ss(s);
    string output;

    while (getline(ss, output, delimiter))
        ans.push_back(output);

    return ans;
}

string replaceWords(vector<string> &dictionary, string sentence)
{
    Node *root = new Node();
    for (string s : dictionary)
        insert(root, s);

    vector<string> words = split(sentence, ',');
    string ans = "";

    for (auto word : words)
    {
        string prefix = searchPrefix(root,word);
        if(prefix=="") ans.append(word);
        else ans.append(prefix);

        ans.append(" ");
    }

    ans.pop_back();
    return ans;
}