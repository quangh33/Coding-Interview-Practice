//
// Created by Hoang, Quang on 2019-09-01.
//

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int res = 0;
        int h[n][m], w[n][m];
        for(int j = 0; j < m; j++) h[0][j] = (a[0][j] == 1);
        for(int i = 0; i < n; i++) w[i][0] = (a[i][0] == 1);

        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++) {
                if (a[i][j] == 0) h[i][j] = 0;
                else h[i][j] = 1 + h[i-1][j];
            }

        for(int j = 1; j < m; j++)
            for(int i = 0; i < n; i++) {
                if (a[i][j] == 0) w[i][j] = 0;
                else w[i][j] = 1 + w[i][j-1];
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (a[i][j] == 1) {
                    int size = min(h[i][j], w[i][j]);
                    for(int k = size; k >= 1; k--) {
                        int r = i - k + 1;
                        int c = j - k + 1;
                        if (w[r][j] >= k && h[i][c] >= k) {
                            res = max(res, k * k);
                        }
                    }
                }

        return res;
    }
};