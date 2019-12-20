//
// Created by Hoang, Quang on 2019-12-20.
//

class Solution {
public:
    int maxUncrossedLines(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        int fx[n + 1][m + 1];
        memset(fx, 0, sizeof(fx));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                fx[i][j] = max(fx[i - 1][j], fx[i][j - 1]);
                if (a[i - 1] == b[j - 1])
                    fx[i][j] = max(fx[i][j], fx[i - 1][j - 1] + 1);

            }
        return fx[n][m];
    }
};