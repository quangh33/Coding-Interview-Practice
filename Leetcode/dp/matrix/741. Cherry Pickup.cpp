//
// Created by Hoang, Quang on 2019-12-14.
//

class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        int fx[n][n][n];

        memset(fx, -1, sizeof(fx));

        fx[0][0][0] = a[0][0];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (i + j > 0 && a[i][j] != -1) {
                    for(int u = 0; u < n; u++) {
                        int v = i + j - u;

                        if (v >= 0 && v < n && a[u][v] != -1) {
                            int delta = (u == i && v == j) ? a[i][j] : a[i][j] + a[u][v];

                            if (i > 0 && u > 0 && a[i-1][j] != -1 && a[u-1][v] != -1 && fx[i-1][j][u-1] != -1)
                                fx[i][j][u] = max(fx[i][j][u], fx[i-1][j][u-1] + delta);

                            if (i > 0 && v > 0 && a[i-1][j] != -1 && a[u][v-1] != -1 && fx[i-1][j][u] != -1)
                                fx[i][j][u] = max(fx[i][j][u], fx[i-1][j][u] + delta);

                            if (j > 0 && u > 0 && a[i][j-1] != -1 && a[u-1][v] != -1 && fx[i][j-1][u-1] != -1)
                                fx[i][j][u] = max(fx[i][j][u], fx[i][j-1][u-1] + delta);

                            if (j > 0 && v > 0 && a[i][j-1] != -1 && a[u][v-1] != -1 && fx[i][j-1][u] != -1)
                                fx[i][j][u] = max(fx[i][j][u], fx[i][j-1][u] + delta);

                        }
                    }
                }

        return fx[n-1][n-1][n-1] == -1 ? 0 : fx[n-1][n-1][n-1];
    }
};