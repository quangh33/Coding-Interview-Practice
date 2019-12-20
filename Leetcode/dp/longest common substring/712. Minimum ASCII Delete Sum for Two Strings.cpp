//
// Created by Hoang, Quang on 2019-12-20.
//

class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size();
        int m = t.size();
        int fx[n+1][m+1];
        memset(fx, 0, sizeof(fx));

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                fx[i][j] = max(fx[i][j-1], fx[i-1][j]);
                if (s[i-1] == t[j-1])
                    fx[i][j] = max(fx[i][j], fx[i-1][j-1] + int(s[i-1]));
            }

        int S = 0, T = 0;
        for(char c: s) S += int(c);
        for(char c: t) T += int(c);
        return S + T - 2 * fx[n][m];
    }
};