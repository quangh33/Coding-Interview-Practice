//
// Created by Hoang, Quang on 2020-01-09.
//

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        if (n == 1) return 0;
        int fx[n][n];
        memset(fx, 0, sizeof(fx));
        for(int i = 0; i < n; i++) {
            fx[i][i] = 0;
            if (i < n-1)
                fx[i][i+1] = s[i] == s[i+1] ? 0 : 1;
        }

        for(int len = 3; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    fx[i][j] = fx[i+1][j-1];
                else fx[i][j] = min(fx[i+1][j], fx[i][j-1]) + 1;
            }
        }

        return fx[0][n-1];
    }
};
