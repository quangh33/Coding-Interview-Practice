//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int res = 1;
        map<char, int> count;
        int i = 0, j = 0;
        count[s[i]]++;
        while (i < n) {
            if (count[s[i]] <= 1) {
                res = max(res, i - j + 1);
                i++;
                if (i < n) count[s[i]]++;
            } else {
                while (count[s[i]] > 1) {
                    count[s[j]]--;
                    j++;
                }
            }
        }
        return res;
    }
};