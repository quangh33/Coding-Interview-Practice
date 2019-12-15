//
// Created by Hoang, Quang on 2019-08-15.
//

// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector <vector<int>> &A) {
        int n = A.size();
        if (n == 0) return 0;
        int fx[n][n];

        int res = 2e9;

        for (int i = 0; i < n; i++) fx[0][i] = A[0][i];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                fx[i][j] = fx[i - 1][j];
                if (j > 0) fx[i][j] = min(fx[i][j], fx[i - 1][j - 1]);
                if (j < n - 1) fx[i][j] = min(fx[i][j], fx[i - 1][j + 1]);
                fx[i][j] += A[i][j];
            }

        for (int i = 0; i < n; i++)
            res = min(res, fx[n - 1][i]);

        return res;
    }
};