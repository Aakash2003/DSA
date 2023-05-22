#include <bits/stdc++.h>
using namespace std;

bool canCross(vector<int> &stones)
{
    int n = stones.size();
    map<int, set<int>> mp;

    for (int i = 0; i < n; i++)
        mp.insert({stones[i], set<int>()});

    mp[stones[0]].insert(1);

    for (int i = 0; i < n; i++)
    {
        int stone = stones[i];
        set<int> jumps = mp[stone];

        for (int jump : jumps)
        {
            int pos = stone + jump;
            if (pos == stones[n - 1])
                return true;

            if (mp.count(pos) > 0)
            {
                if (jump - 1 > 0)
                    mp[pos].insert(jump - 1);

                mp[pos].insert(jump);
                mp[pos].insert(jump + 1);
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i];
    string ans[] = {"No", "Yes"};
    cout << ans[canCross(stones)] << endl;
}