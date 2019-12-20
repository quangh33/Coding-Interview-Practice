//
// Created by Hoang, Quang on 2019-12-20.
//

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        if (n == 0) return m;
        if (m == 0) return n;

        int fx[n+1][m+1];
        memset(fx, 0, sizeof(fx));

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) {
                fx[i][j] = max(fx[i-1][j], fx[i][j-1]);
                if (s[i-1] == t[j-1])
                    fx[i][j] = max(fx[i][j], fx[i-1][j-1] + 1);
            }

        return m + n - 2 * fx[n][m];
    }
};