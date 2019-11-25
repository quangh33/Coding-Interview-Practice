//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    bool canConvert(string s, string t) {
        if (s == t) return true;
        unordered_map<char, vector<char>> m;
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < n; i++)
                if (s[i] == c) {
                    m[c].push_back(t[i]);
                }

            for (int i = 1; i < m[c].size(); i++)
                if (m[c][i] != m[c][i - 1]) return false;
        }
        return set(t.begin(), t.end()).size() < 26;
    }
};