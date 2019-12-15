//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:

    bool ok(string s, string t) {
        if (s.size() - t.size() != 1) return false;
        int i = 0;
        int j = 0;
        int diff = 0;
        while (i < s.size() && j < t.size()) {
            if (diff > 1) return false;
            if (s[i] != t[j]) {
                j--;
                diff++;
            }
            i++;
            j++;
        }
        return diff <= 1;
    }

    int longestStrChain(vector <string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        if (n == 0) return 0;
        int fx[n];
        fx[0] = 1;
        int res = 1;
        for (int i = 1; i < n; i++) {
            fx[i] = 1;
            for (int j = 0; j < i; j++)
                if (ok(words[i], words[j])) fx[i] = max(fx[i], fx[j] + 1);
            res = max(res, fx[i]);
        }
        return res;
    }
};
