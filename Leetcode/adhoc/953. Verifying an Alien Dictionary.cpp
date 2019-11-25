//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int id[26];

    bool ok(string s, string t) {
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < min(n, m); i++) {
            if (s[i] != t[i]) {
                if (id[s[i] - 'a'] > id[t[i] - 'a']) return false;
                else return true;
            }
        }
        if (n > m) return false;
        return true;
    }

    bool isAlienSorted(vector <string> &words, string order) {
        int i = -1;
        for (char c: order) {
            id[c - 'a'] = ++i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            if (!ok(words[i], words[i + 1])) return false;
        }
        return true;
    }
};