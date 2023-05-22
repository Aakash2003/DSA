#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int n = words.size();
    vector<string> ans;

    int i = 0;
    while (i < n)
    {
        int wordCnt = words[i].length();
        int j = i + 1;
        int spaces = 0;

        while (j < n && wordCnt + spaces + words[j].length() + 1 <= maxWidth)
        {
            wordCnt += words[j].length();
            spaces++, j++;
        }

        int left = maxWidth - wordCnt;
        int least = 0, extra = 0;

        if (spaces != 0)
            least = left / spaces;
        if (spaces != 0)
            extra = left % spaces;
        if (j == n)
            least = 1, extra = 0;

        string s = "";
        for (int k = i; k < j; k++)
        {
            s.append(words[k]);
            if (k == j - 1)
                break;
            for (int e = 0; e < least; e++)
                s.append(" ");
            if (extra > 0)
            {
                s.append(" ");
                extra--;
            }
        }

        while (s.length() < maxWidth)
            s.append(" ");
        ans.push_back(s);
        i = j;
    }

    return ans;
}
