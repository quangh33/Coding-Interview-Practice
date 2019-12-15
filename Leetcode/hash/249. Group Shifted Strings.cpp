//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    long long MOD = 1e9 + 7;

    long long hash(vector<int> a) {
        long long value = 0;
        for (int i = 0; i < a.size(); i++)
            value = (value * 26 + a[i]) % MOD;
        return value;
    }

    long long cal(string s) {
        vector<int> a;
        for (int i = 1; i < s.size(); i++) {
            a.push_back((int(s[i]) - int(s[i - 1]) + 26) % 26);
        }
        a.push_back(s.size());
        return hash(a);
    }

    unordered_map<long long, vector<string>> m;

    vector <vector<string>> groupStrings(vector <string> &strings) {
        vector <vector<string>> res;
        if (strings.size() == 0) return res;

        for (string s: strings) {
            long long h = cal(s);
            m[h].push_back(s);
        }

        for (auto pair: m) {
            vector <string> group;
            for (string s: pair.second)
                group.push_back(s);
            res.push_back(group);
        }
        return res;
    }
};