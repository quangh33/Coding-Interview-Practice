//
// Created by Hoang, Quang on 2019-08-24.
//
// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int fx[n][n];
        for(int i = 0; i < n; i++) {
            fx[i][i] = 1;
            if (i < n-1) fx[i][i+1] = s[i] == s[i+1] ? 2 : 1;
        }

        for(int len = 3; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                fx[i][j] = max(fx[i+1][j], fx[i][j-1]);
                if (s[i] == s[j]) fx[i][j] = max(fx[i][j], fx[i+1][j-1] + 2);
            }
        }
        return fx[0][n-1];
    }
};
