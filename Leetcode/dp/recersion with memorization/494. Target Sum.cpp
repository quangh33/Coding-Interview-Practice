//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int fx[21][2010];
    int offset = 1000;

    int cal(int i, int s, vector<int> a, int target) {
        if (fx[i][s+offset] != -1) return fx[i][s+offset];

        int n = a.size();
        if (i == n) {
            fx[n][s+offset] = (s == target);
            return (s == target);
        }
        fx[i][s+offset] = cal(i+1, s + a[i], a, target)
                          + cal(i+1, s - a[i], a, target);

        return fx[i][s+offset];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        memset(fx, -1, sizeof(fx));
        return cal(0, 0, nums, S);
    }
};
