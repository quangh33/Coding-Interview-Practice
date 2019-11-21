//
// Created by Hoang, Quang on 2019-11-20.
//

class Solution {
public:
    int maxSumDivThree(vector<int> &a) {
        int n = a.size();
        int fx[n][3];
        memset(fx, -1, sizeof(fx));
        fx[0][0] = 0;
        fx[0][a[0] % 3] = a[0];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < 3; j++) {
                fx[i][j] = fx[i - 1][j];
                int k = (j - a[i] % 3 + 3) % 3;
                if (fx[i - 1][k] != -1)
                    fx[i][j] = max(fx[i - 1][k] + a[i], fx[i][j]);
            }


        if (fx[n - 1][0] == -1) return 0;
        return fx[n - 1][0];
    }
};
