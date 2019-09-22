//
// Created by Hoang, Quang on 2019-09-22.
//

// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_set<char> a;
        unordered_map<char, int> count;

        int n = s.size();
        if (n == 0) return 0;
        int i = 0, j = 0, res = 0;
        a.insert(s[0]);
        count[s[0]] = 1;
        while (i < n) {
            if (a.size() <= 2) {
                res = max(res, i - j + 1);
                i++;
                if (i < n) {
                    a.insert(s[i]);
                    count[s[i]]++;
                }
            } else {
                count[s[j]]--;
                if (count[s[j]] == 0) a.erase(s[j]);
                j++;
            }
        }
        return res;
    }
};

