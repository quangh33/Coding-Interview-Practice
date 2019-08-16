//
// Created by Hoang, Quang on 2019-08-15.
//

class Solution {
public:
    bool isSubsequence(string t, string s) {
        int n = s.length();
        int m = t.length();

        if (m == 0) return true;
        if (n == 0) return false;

        int next[n+1][30];
        for(int i = 0; i <= 26; i++) {
            next[n-1][i] = -1;
            if (n > 1) {
                next[n-2][i] = s[n-1] == char(i+int('a')) ? n-1 : -1;
            }
        }

        for(int i = n-3; i >= 0; i--) {
            for(int j = 0; j <= 26; j++) {
                next[i][j] = s[i+1] == char(j+int('a')) ? i+1 : next[i+1][j];
            }
        }

        for(int i = 0; i <= 26; i++) {
            next[n][i] = s[0] == char(i+int('a')) ? 0 : next[0][i];
        }

        bool ok = true;
        int pos = next[n][t[0] - 'a'];

        if (pos == -1) return false;
        for(int i = 1; i < m; i++) {
            pos = next[pos][t[i]-'a'];
            if (pos == -1) return false;
        }
        return true;
    }
};