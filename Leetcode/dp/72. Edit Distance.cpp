//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (n * m == 0) return m + n;
        int fx[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            fx[i][0] = i;

        for (int j = 0; j <= m; j++)
            fx[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                fx[i][j] = min(fx[i - 1][j], fx[i][j - 1]) + 1;

                if (a[i - 1] == b[j - 1])
                    fx[i][j] = min(fx[i][j], fx[i - 1][j - 1]);
                else
                    fx[i][j] = min(fx[i][j], fx[i - 1][j - 1] + 1);
            }

        return fx[n][m];
    }
};