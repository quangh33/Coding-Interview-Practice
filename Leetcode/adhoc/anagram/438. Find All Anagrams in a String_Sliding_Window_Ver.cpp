//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/

class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> count;
        int n = s.size();
        int m = p.size();
        vector<int> res;
        if (m > n) return res;
        for (char c: p) count[c]++;
        int matchSize = count.size();

        int i = 0, j = 0;
        while (i < n) {
            if (count.find(s[i]) != count.end()) {
                count[s[i]]--;
                if (count[s[i]] == 0) matchSize--;
            }

            if (i - j + 1 == m) {
                if (matchSize == 0) res.push_back(j);
                if (count.find(s[j]) != count.end()) {
                    if (count[s[j]] == 0) matchSize++;
                    count[s[j]]++;
                }
                j++;
            }

            i++;
        }
        return res;
    }
};

