//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        for(char c: s) count[c]++;
        int res = 0;
        bool odd = false;
        for(auto pair: count) {
            res = res + pair.second / 2 * 2;
            if (pair.second % 2 == 1) odd = true;
        }
        return res + int(odd);
    }
};