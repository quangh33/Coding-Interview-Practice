//
// Created by Hoang, Quang on 2019-09-01.
//

// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int> &a) {
        int n = a.size();
        if (n == 0) return 0;
        int fx[n][2];
        fx[0][1] = fx[0][0] = 1;
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] < a[i]) {
                fx[i][1] = fx[i - 1][0] + 1;
            } else fx[i][1] = 1;

            if (a[i - 1] > a[i]) {
                fx[i][0] = fx[i - 1][1] + 1;
            } else fx[i][0] = 1;

            res = max(res, fx[i][0]);
            res = max(res, fx[i][1]);
        }
        return res;
    }
};