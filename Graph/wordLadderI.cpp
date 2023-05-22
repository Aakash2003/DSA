#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    set<string> s(wordList.begin(),wordList.end());
    s.erase(beginWord);

    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        string word = itr.first;
        int length = itr.second;
        int n = word.length();

        if(word==endWord) return length;
        
        for(int i=0;i<n;i++)
        {
            char original = word[i];

            for(char ch='a';ch<='z';ch++) 
            {
                word[i] = ch;
                if(s.count(word)>0)
                {
                    s.erase(word);
                    q.push({word,length+1});
                }
            }

            word[i] = original;
        }
    }
    
    return 0;
}

int main()
{
    string beginWord,endWord;
    cin>>beginWord>>endWord;

    int n;
    cin>>n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++) cin>>wordList[i];

    cout<<ladderLength(beginWord,endWord,wordList)<<endl;
}