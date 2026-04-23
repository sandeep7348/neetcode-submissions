#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto &m = mp[key];
        auto it = m.upper_bound(timestamp);

        if (it == m.begin()) return "";
        
        --it; 
        return it->second;
    }
};