//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool isPalin(string s, int u, int v) {
        int i = u, j = v;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-i-1]) {
                int j = n - i - 1;
                return (isPalin(s, i+1, j) || isPalin(s, i, j-1));
            }
        }
        return true;
    }
};