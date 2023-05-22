#include <bits/stdc++.h>
using namespace std;

struct suffix
{
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
    if (a.rank[0] == b.rank[0])
    {
        if (a.rank[1] < b.rank[1])
            return 1;
        else
            return 0;
    }
    else
    {
        if (a.rank[0] < b.rank[0])
            return 1;
        else
            return 0;
    }
}

vector<int> buildSuffixArray(string txt)
{
    int n = txt.length();
    struct suffix suffixes[n];

    for(int i=0;i<n;i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = (int)txt[i];

        if(i+1<n) suffixes[i].rank[1] = (int)txt[i+1];
        else suffixes[i].rank[1] = -1;
    }

    sort(suffixes,suffixes+n,cmp);

    int ind[n];
    for(int k=4;k<2*n;k++)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for(int i=1;i<n;i++)
        {
            if(suffixes[i].rank[0]==prev_rank && suffixes[i].rank[1]==suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }

            ind[suffixes[i].index] = i;
        }

        for(int i=0;i<n;i++)
        {
            int nextIndex = suffixes[i].index + k/2;
            if(nextIndex<n) suffixes[i].rank[1] = suffixes[ind[nextIndex]].rank[0];
            else suffixes[i].rank[1] = -1;
        }

        sort(suffixes,suffixes+n,cmp);
    }

    vector<int> suffixArr;
    for(int i=0;i<n;i++) suffixArr.push_back(suffixes[i].index);

    return suffixArr;
}

vector<int> kasai(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();

    vector<int> lcp(n);
    vector<int> inv_suffix(n);

    for (int i = 0; i < n; i++)
        inv_suffix[suffixArr[i]] = i;

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (inv_suffix[i] == n - 1)
        {
            k = 0;
            continue;
        }

        int j = suffixArr[inv_suffix[i] + 1];

        while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
            k++;

        lcp[inv_suffix[i]] = k;
        if (k > 0)
            k--;
    }

    return lcp;
}

int main()
{
    string s;
    cin >> s;

    vector<int> suffixArr = buildSuffixArray(s);
    vector<int> lcp = kasai(s, suffixArr);

    cout << "Suffix Array: ";
    for (auto i : suffixArr)
        cout << i << " ";

    cout << endl
         << "Lcp Array: ";
    for (auto i : lcp)
        cout << i << " ";
}