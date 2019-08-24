//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        bool fx[n][n];
        int res = 0;
        for(int i = 0; i < n; i++) {
            fx[i][i] = true;
            if (i < n-1)
                fx[i][i+1] = s[i] == s[i+1];
        }

        for(int len = 3; len <= n; len++)
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) fx[i][j] = fx[i+1][j-1]; else fx[i][j] = false;
            }

        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                res = res + fx[i][j];

        return res;
    }
};
