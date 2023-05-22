#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<char> ch(m);
    for (int i = 0; i < m; i++)
        cin >> ch[i];

    vector<bool> flag(26);
    for (int i = 0; i < m; i++)
        flag[ch[i] - 'a'] = true;

    int freq[k][26];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 26; j++)
            freq[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
        freq[i % k][s[i] - 'a']++;

    int total = 0;
    for (int i = 0; i < k; i++)
    {
        int maxi = 0, sum = 0;
        for (int j = 0; j < 26; j++)
        {
            sum += freq[i][j];
            if (freq[i][j] > maxi && flag[j] == true)
                maxi = freq[i][j];
        }

        total += (sum - maxi);
    }

    cout << total << endl;
}