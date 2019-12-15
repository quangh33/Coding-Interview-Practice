//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<char, int> count;
        if (m > n) return "";

        for(char c: t) count[c]++;
        int matchSize = count.size();

        int i = 0, j = 0;
        int minLen = n+1;
        string res = "";

        while (i < n) {
            if (count.find(s[i]) != count.end()) {
                count[s[i]]--;
                if (count[s[i]] == 0) matchSize--;
            }

            while (matchSize == 0) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    res = s.substr(j, i - j + 1);
                }

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