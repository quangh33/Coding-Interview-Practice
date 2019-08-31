//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    int change(int s, vector<int>& a) {
        int n = a.size();
        if (n == 0) return (s == 0);
        long long fx[s+1][n];
        memset(fx, 0, sizeof(fx));
        for(int i = 0; i < n; i++) fx[0][i] = 1;
        for(int i = 1; i <= s; i++)
            for(int j = 0; j < n; j++) {
                fx[i][j] = j > 0 ? fx[i][j-1] : 0;
                if (i >= a[j]) {
                    fx[i][j] += fx[i-a[j]][j];
                }
            }

        return fx[s][n-1];
    }
};
