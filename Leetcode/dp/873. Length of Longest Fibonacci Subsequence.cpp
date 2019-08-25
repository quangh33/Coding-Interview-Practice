//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int> &a) {
        int n = a.size();
        int fx[n][n];
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[a[i]] = i;

        int res = 0;

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                fx[i][j] = 2;
                int delta = a[j] - a[i];
                if (pos.count(delta)) {
                    int k = pos[delta];
                    if (k < i) {
                        fx[i][j] = max(fx[i][j], fx[k][i] + 1);
                    }
                }
                res = max(res, fx[i][j]);
            }

        return res == 2 ? 0 : res;
    }
};

