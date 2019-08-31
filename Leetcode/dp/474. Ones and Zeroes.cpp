//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int fx[m+1][n+1];
        memset(fx, 0, sizeof(fx));

        for(string s: strs) {
            int one = 0, zero = 0;
            for(char c: s) {
                if (c == '0') zero++;
                else one++;
            }
            for(int i = m; i >= zero; i--)
                for(int j = n; j >= one; j--)
                    fx[i][j] = max(fx[i][j], fx[i-zero][j-one] + 1);
        }

        return fx[m][n];
    }
};