#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    TimeMap()
    {
        string key;
        string value;
    }

    map<string, map<int, string, greater<int>>> mp;

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (mp.count(key) == 0)
            return "";

        auto itr = mp[key].lower_bound(timestamp);
        if (itr == mp[key].end())
            return "";
        else
            return itr->second;
    }
};